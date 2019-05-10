/*
 * xyz_base.h
 *
 *  Created on: 3 de abr. de 2017
 *      Author: gmandrut
 */

#ifndef SRC_ABC_BASE_H_
#define SRC_ABC_BASE_H_
#include "xyz_base.h"

#define	SALIDA	1
#define	ENTRADA	0
#define	GPIO	0

#define		BEEPER		FIO0PIN28		//!< Beeper

#define		relay1		FIO0PIN23		//!< Relays
#define		relay2		FIO0PIN21
#define		relay0		FIO2PIN0
#define		relay3		FIO0PIN27

#define		led0		FIO2PIN1		//!< led
#define		led1		FIO2PIN2
#define		led2		FIO2PIN3

#define		in_0		FIO1PIN26		//!< input digital
#define		in_1		FIO4PIN29
#define		in_2		FIO2PIN11

#define		tec_0		FIO2PIN10
#define		tec_1		FIO0PIN18
#define		tec_2		FIO0PIN11
#define		tec_3 		FIO2PIN13
#define		tec_4 		FIO1PIN26

#endif /* SRC_ABC_BASE_H_ */
