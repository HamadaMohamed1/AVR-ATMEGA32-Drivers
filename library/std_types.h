/*
 * std_types.h
 *
 *  Created on: Nov 4, 2023
 *      Author: hamad
 */

#ifndef LIBRARY_STD_TYPES_H_
#define LIBRARY_STD_TYPES_H_

/*---------- Includes ----------*/
#include <stdio.h>
/*---------- Section: Data Type Declarations ----------*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;

typedef uint8 Std_ReturnType;

/*---------- Section: Macro Declarations ----------*/

/**
 * Return of any function one of these :
 * 								(E_OK) : The function done successfully
 * 								(E_NOT_OK) : The function has a problem to perform this action
 */
#define E_OK         (Std_ReturnType)0x01
#define E_NOT_OK     (Std_ReturnType)0x00




#endif /* LIBRARY_STD_TYPES_H_ */
