#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_
/*-----------------------------------------------------------------*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <unistd.h>

#define INITIAL_VALUE 0x00000000000000
//#define INITIAL_VALUE 0xffffffffffffff
#define INITIAL_ADDITION 0x89
#define SHARED_MEM_KEY 508
/*-----------------------------------------------------------------*/
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};
/*-----------------------------------------------------------------*/
int createMemBlock(int arg_key);
char *getMemData(int shmid);
void destroyMemBlock(int shmid);
/*-----------------------------------------------------------------*/
#endif /* MEMORYMANAGER_H_ */
