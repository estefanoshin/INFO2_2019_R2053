/*-----------------------------------------------------------------*/
#include "memorymanager.h"
/*-----------------------------------------------------------------*/
int createMemBlock(int arg_key)
{
    key_t key = arg_key;
    int shmid = shmget(key, 1024, 0644 | IPC_CREAT);

    return shmid;
}
/*-----------------------------------------------------------------*/
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
/*-----------------------------------------------------------------*/
void destroyMemBlock(int shmid)
{
    shmctl(shmid, IPC_RMID, NULL);
}
/*-----------------------------------------------------------------*/
