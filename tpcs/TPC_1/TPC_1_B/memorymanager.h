#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <stdlib.h>

int createMemBlock(int arg_key)
{
    key_t key = arg_key;
    int shmid = shmget(key, 1024, 0644 | IPC_CREAT | IPC_EXCL);

    return shmid;
}

char *getMemData(int shmid)
{
    char *data;

    data = shmat(shmid, (void *)0, 0);

    //eliminacion del bloque, si hay error
    if(data == (void*)-1)
    {
        puts(data);
        puts("ERROR");
        shmctl(shmid, IPC_RMID, NULL);
        exit(1);
    }

    //eliminacion del bloque
    //shmctl(shmid, IPC_RMID, NULL);

    return data;
}

void destroyMemBlock(int shmid)
{
    shmctl(shmid, IPC_RMID, NULL);
}


#endif // MEMORYMANAGER_H
