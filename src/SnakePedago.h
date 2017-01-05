/*
 * SnakePedago.h
 *
 *  Created on: 31 déc. 2015
 *      Author: philippe
 */

#ifndef SNAKEPEDAGO_H_
#define SNAKEPEDAGO_H_

#include "Game.h"

class SnakePedago: public Game {
public:
	SnakePedago(Interface* i);
	virtual ~SnakePedago();
	void initboard();
	void initplayers();
	bool testtour(Player p);

};

#endif /* SNAKEPEDAGO_H_ */
