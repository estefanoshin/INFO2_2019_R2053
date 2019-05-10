/*
 * xyz_io.h
 *
 *  Created on: 3 de abr. de 2017
 *      Author: gmandrut
 */

#ifndef SRC_XYZ_IO_H_
#define SRC_XYZ_IO_H_

#include "registros.h"
#include "xyz_base.h"

/** -------------------------------------------------------------------------------------
 * Macros de uso general
 */
#define	ON		1
#define	OFF		0

/** -------------------------------------------------------------------------------------
 *Salidas de Rele
 */

#define		RELAY0		0				//!< Numero de relay
#define		RELAY1		1
#define		RELAY2		2

/** -------------------------------------------------------------------------------------
 * Entradas
 */

#define		KEY_0		0				//!< Numero de Teclado
#define		KEY_1		1
#define		KEY_2		2
#define		KEY_3		3
#define		KEY_4		4

#define		IN_1		1				//!< Numero de Entrada Digital
#define		IN_2		2


/** -------------------------------------------------------------------------------------
 * Declaracion de Funciones
 */

// nro de Rele - estado ON/OFF
void Relays (char , char );

// nro de entrada  - return ON/OFF

int Dig_Inputs (char);
int Teclado ( char );

void Inic_Test (void );
void Inic_Teclado_BB(void);
void Inic_Relays( void );
void Inic_Leds(void);
void Inic_Entradas(void);
void Inicializar_io(void);

void Led (char n, char estado);



#endif /* SRC_XYZ_IO_H_ */
