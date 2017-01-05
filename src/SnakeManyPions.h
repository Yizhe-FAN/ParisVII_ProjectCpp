/*
 * SnakeManyPions.h
 *
 *  Created on: 31 déc. 2015
 *      Author: philippe
 */

#ifndef SNAKEMANYPIONS_H_
#define SNAKEMANYPIONS_H_

#include "Game.h"

class SnakeManyPions: public Game {
public:
	SnakeManyPions(Interface* i);
	virtual ~SnakeManyPions();
	void initboard();
	void initplayers();

};

#endif /* SNAKEMANYPIONS_H_ */
