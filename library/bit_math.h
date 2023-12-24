/*
 * bit_math.h
 *
 *  Created on: Nov 5, 2023
 *      Author: hamada
 */

#ifndef LIBRARY_BIT_MATH_H_
#define LIBRARY_BIT_MATH_H_

/*---------- Section: Macro Functions Declarations ----------*/
/**
 * @breif Set a specific bit in a specific register
 */
#define SET_BIT(REG,BIT_POSN)     (REG |= (1 << BIT_POSN))
/**
 * @breif Clear a specific bit in a specific register
 */
#define CLEAR_BIT(REG,BIT_POSN)   (REG &= ~(1 << BIT_POSN))
/**
 * @breif Toggle a specific bit in a specific register
 */
#define TOGGLE_BIT(REG,BIT_POSN)  (REG ^= (1 << BIT_POSN))
/**
 * @breif Read a specific bit in a specific register
 */
#define READ_BIT(REG,BIT_POSN)    ((REG >> BIT_POSN) & 1)


#endif /* LIBRARY_BIT_MATH_H_ */
