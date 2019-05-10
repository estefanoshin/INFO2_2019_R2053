#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "filemanager.h"

#define FILE_PATH "/home/oem/test_file"
#define FTOK_ID 'E'

struct my_msgbuf
{
    long mtype;
    char mtext[200];
};

int main()
{
    FILE * file = fopen(FILE_PATH, "r+");
    key_t key;
    int msgQueue;
    struct my_msgbuf buf;

    if ( (key = ftok(FILE_PATH, FTOK_ID) ) == -1 )
    {
        perror("ftok ERR");
        exit(1);
    }

    msgQueue = msgget(key, 0666 | IPC_CREAT );

    if(getchar() != 0x1B)
    {
        if(fgets(buf.mtext, sizeof buf.mtext, file) != NULL) {
                unsigned long len = strlen( buf.mtext);

                /* ditch newline at end, if it exists */
                if (buf.mtext[len-1] == '\n')
                {
                    buf.mtext[len-1] = '\0';
                }

                if (msgsnd(msgQueue, &buf, len+1, 0) == -1) /* +1 for '\0' */
                {
                    perror("msgsnd");
                }
                else
                {
                    readMyFile(FILE_PATH);
                }

                fclose(file);
                main();
        }
    }
    else
    {
        exit(1);
    }

    return 0;
}
