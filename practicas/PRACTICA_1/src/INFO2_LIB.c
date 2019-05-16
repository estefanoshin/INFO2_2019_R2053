<<<<<<< HEAD:practicas/PRACTICA_1/src/INFO2_LIB.c
/*
===============================================================================
 Name        : INFO2_LIB.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

#include <xyz_timer.h>

#include <xyz_io.h>

#include <xyz_base.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void)
{
    // Force the counter to be placed into memory
    volatile static int i = 0 ;

    int8_t final0 = 0, final1 =0, final2 = 0,final3 = 0;
    int8_t in1 = 0, in2 = 0;

    // ver de inicializar io

    Inicializar_io();

    InitTimer();

    set_timer(0,10);

    // Enter an infinite loop, just incrementing a counter
    while(1)
    {
    	if((final0=is_timer_end(0)))
            final0 = 4;

    	final0 = Teclado(1);          // P0.18
    	final1 = Teclado(2);          // P0.11
    	final2 = Teclado(3);          // P2.13
    	final3 = Teclado(4);          // P1.16

    	in1 = Dig_Inputs(1);          // P4.29
    	in2 = Dig_Inputs(2);          // P2.11

    	Relays (0 , ON );             // P2.0
    	Relays (0 , OFF);
    	Relays (1 , ON);              // P0.23
    	Relays (1 , OFF);
    	Relays (2 , ON );             // P0.21
    	Relays (2 , OFF );
/*
    	Led (1, OFF);                 // P2.1
    	Led (1, ON);
    	Led (2, OFF);                 // P2.2
    	Led (2, ON);
    	Led (3, OFF);                 // P2.3
*/
        if(is_timer_end(0))
        {
    	  Led (0, OFF);
    	  Led (1, OFF);
    	  Led (2, OFF);
        }

    	i++ ;
    }
    return 0 ;
}
=======
/*
===============================================================================
 Name        : INFO2_LIB.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

#include <xyz_timer.h>

#include <xyz_io.h>

#include <xyz_base.h>

#define TRUE 1
#define FALSE 0
#define ON 1
#define OFF 0

#define TIMER_SECONDS 10

#define IS_FIN_CARRERA_ABIERTO Teclado(4)
#define IS_FIN_CARRERA_CERRADO Teclado(3)

#define ABRIR(state) Relays(1, state)
#define CERRAR(state) Relays(2, state)

#define SENSOR_PUERTA_EXTERNA Dig_Inputs(1)
#define SENSOR_PUERTA_INTERNA Dig_Inputs(2)

#define INIT_TIMER(time) set_timer(0,time)
#define IS_TIMEOUT is_timer_end(0)

enum STATES {ABIERTO, CERRADO, ABRIENDO, CERRANDO};

int main(void)
{
	INIT_TIMER(TIMER_SECONDS);
	CERRAR(ON);
	static STATES estado = CERRADO;

    while(1)
    {
    	switch (estados)
    		    	{
    					case ABIERTO:
    						ABRIR(OFF);
    						if((SENSOR_PUERTA_EXTERNA == FALSE && SENSOR_PUERTA_INTERNA == FALSE) || IS_TIMEOUT == TRUE)
    							estado = CERRANDO;
    						break;

    					case CERRADO:
    						CERRAR(OFF);
    						if(SENSOR_PUERTA_EXTERNA == TRUE || SENSOR_PUERTA_INTERNA == TRUE)
    							estado = ABRIENDO;
    						break;

    					case ABRIENDO:
    						CERRAR(OFF);
    						ABRIR(ON);
    						if((SENSOR_PUERTA_EXTERNA == FALSE && SENSOR_PUERTA_INTERNA == FALSE) || IS_TIMEOUT == TRUE)
    							estado = CERRANDO;
    						break;

    						if(IS_FIN_CARRERA_ABIERTO == TRUE)
    							estado = ABIERTO;
    						break;

    					case CERRANDO:
    						ABRIR(OFF);
    						CERRAR(ON);
    						if((SENSOR_PUERTA_EXTERNA == TRUE || SENSOR_PUERTA_INTERNA == TRUE))
    							estado = ABRIENDO;
    						break;

    						if(IS_FIN_CARRERA_CERRADO == TRUE)
    							estado = CERRADO;
    						break;

    					default:
    						//TODO ...
    						break;
    				}
    }
    return 0 ;
}
>>>>>>> develop:practicas/practica_1/src/practica_1.c
