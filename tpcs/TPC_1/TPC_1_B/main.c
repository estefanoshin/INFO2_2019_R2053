#include "memorymanager.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_VALUE 0x00000000000000
//#define INITIAL_VALUE 0xffffffffffffff
#define INITIAL_ADDITION 0x89
#define SHARED_MEM_KEY 508

/**
 * @brief main debe ingresar ESC para terminar el programa
 * @return
 */
int main()
{
    int shmid = createMemBlock(SHARED_MEM_KEY);
    char *data = getMemData( shmid );
    //destroyMemBlock(shmid);

    long long value = INITIAL_VALUE, auxValue = value;
    unsigned int addition = INITIAL_ADDITION;

    puts("Presione Enter para continuar.. \n\n");

    while(1)
    {
        if(getchar() == 0x1B)
        {
            destroyMemBlock(shmid);
            exit(1);
        }
        if(value > 0xffffffffffffff)
        {
            value = 0x00000000000000;
            addition = INITIAL_ADDITION;
        }

        for (int i = 0; i < 14; i++)
        {
            if(auxValue != 0)
            {
                addition += auxValue % 0x10;
                auxValue = auxValue / 0x10;
            }
        }

        auxValue = ++value;

        data = (char*) ((value * 0x100) + (addition % 0x100));

        printf("%016x \n", (unsigned int) data);
        addition = INITIAL_ADDITION;

    }

    //return 0;
}
