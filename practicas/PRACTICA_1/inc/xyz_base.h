/*
 * xyz_base.h
 *
 *  Created on: 3 de abr. de 2017
 *      Author: gmandrut
 */

#ifndef SRC_XYZ_BASE_H_
#define SRC_XYZ_BASE_H_


#define		__R			volatile const
#define		__W			volatile
#define		__RW		volatile

typedef 	unsigned int 		uint32_t;
typedef 	unsigned short 		uint16_t;
typedef 	unsigned char 		uint8_t;
typedef 	__RW uint32_t 		registro;  //!< defino un tipo 'registro' uint32_t volatile.


#endif /* SRC_XYZ_BASE_H_ */
