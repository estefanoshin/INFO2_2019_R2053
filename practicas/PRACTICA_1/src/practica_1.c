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
