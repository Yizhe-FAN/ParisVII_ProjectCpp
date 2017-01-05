/*
 * Board.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#include "Board.h"
#include <vector>
using namespace std;

Board::Board(int s):boardsize(s) {

	cells.resize(s);             // resize the controlled sequence
	for(int i=0; i<s; ++i){
	    cells[i]=Cell();

}
}
Board::~Board() {
	// TODO Auto-generated destructor stub
}

int Board::getsize(){
	return boardsize;
}

/*std::vector<Cell> Board::getcells(){
	return cells;
}
*/
Cell*  Board::getcell(int n) {
	return &cells[n];
}
