/*
 * xyz_timer.h
 *
 *  Created on: 20 de abr. de 2017
 *      Author: gmandrut
 */

#ifndef XYZ_TIMER_H_
#define XYZ_TIMER_H_
#include "registros.h"

void set_timer(int , uint32_t );

int is_timer_end(int tt);

void InitTimer( void );
#endif
