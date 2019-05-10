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
