/*
 * SnakesLadders.h
 *
 *  Created on: 28 déc. 2015
 *      Author: philippe
 */

#ifndef SNAKESLADDERS_H_
#define SNAKESLADDERS_H_

#include "Game.h"

class SnakesLadders: public Game {
public:
	SnakesLadders(Interface* i);
	virtual ~SnakesLadders();
	void initboard();
	void initplayers();
};

#endif /* SNAKESLADDERS_H_ */
