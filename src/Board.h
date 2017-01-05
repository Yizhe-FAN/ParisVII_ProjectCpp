/*
 * Board.h
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
#include <vector>
#include "Cell.h"

class Board {
public:
	Board(int s);
	virtual ~Board();
	int getsize();
	std::vector<Cell> getcells();
	Cell*  getcell(int n);
protected:
	std::vector<Cell> cells;
	int boardsize;
};

#endif /* BOARD_H_ */
