#include "../memorymanager.h"

/**
 * @brief Client
 */
int main()
{
	/*semaforos*/
	key_t Clave;
	int Id_Semaforo;
	struct sembuf Operacion;
	union semun arg;
	int i=0;

	Clave = ftok ("/bin/ls", 33);

	/*share memory*/
    int shmid = createMemBlock(SHARED_MEM_KEY);
    char *data = getMemData( shmid );
    destroyMemBlock(shmid);

    long long value = INITIAL_VALUE, auxValue = value;
    unsigned int addition = INITIAL_ADDITION;

	if (Clave == (key_t)-1)
	{
		perror("ftok");
		exit(0);
	}

	Id_Semaforo = semget (Clave, 10, 0600 | IPC_CREAT);
	if (Id_Semaforo == -1)
	{
		perror("semget");
		exit (0);
	}

	arg.val = 1;
	semctl (Id_Semaforo, 0, SETVAL, &arg);

	Operacion.sem_num = 0;
	Operacion.sem_op = -1;
	Operacion.sem_flg = 0;

	while (1)
	{
		printf( "Esperando Semáforo: %d\n", i);

/*        if(getchar() == 0x1B)
        {
            destroyMemBlock(shmid);
            exit(1);
        }
*/
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

		semop (Id_Semaforo, &Operacion, 1);

		printf( "salgo del Semáforo: %d\n", i);

		i++;
	}

	return EXIT_SUCCESS;
}
