/*
 * Dice.h
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#ifndef HEADER_DICE_H_
#define HEADER_DICE_H_

class Dice {
public:
	Dice(int n);
	Dice();
	virtual ~Dice();
	 int throwDice();
protected:
	 int faces;
};

#endif /* HEADER_DICE_H_ */
