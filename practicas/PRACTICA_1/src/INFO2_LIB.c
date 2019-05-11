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

#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0

#define TIMER 0
#define TIEMPO_SEGUNDOS 10

uint8_t MOTOR_ABRIR;
uint8_t MOTOR_CERRAR;

enum ESTADOS
{
	CERRADO, ABIERTO, ABRIENDO, CERRANDO
};

int abierto()
{
	MOTOR_ABRIR = OFF;
	MOTOR_CERRAR = OFF;
	return Teclado(4);
}

int cerrado()
{
	MOTOR_ABRIR = OFF;
	MOTOR_CERRAR = OFF;
	return Teclado(3);
}

void init()
{
	set_timer(TIMER, TIEMPO_SEGUNDOS);
	cerrado();
}

int sensor_salida()
{
	return Dig_Inputs(1);
}

int sensor_entrada()
{
	return Dig_Inputs(2);
}

void abriendo(int state)
{
	MOTOR_CERRAR = OFF;
	MOTOR_ABRIR = ON;
	Relays(2, state);
}

void cerrando(int state)
{
	MOTOR_ABRIR = OFF;
	MOTOR_CERRAR = ON;
	Relays(1, state);
}

int main(void)
{
	init();
	cerrado();

	while (1) {

		if(sensor_entrada() == ON || sensor_salida() == ON)
		{
			abriendo(ON);
		}

		if(sensor_entrada() == OFF && sensor_salida() == OFF)
		{
			cerrando(ON);
		}

		if(abierto() == TRUE && (sensor_entrada() == ON || sensor_salida() == ON) && is_timer_end(TIMER) == TRUE)
		{
			cerrando(ON);
		}

	}

	return 0;
}
