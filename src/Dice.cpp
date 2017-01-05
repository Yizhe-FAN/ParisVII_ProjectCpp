/*
 * Dice.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#include "Dice.h"
#include <stdlib.h>
#include <time.h>

using namespace std;


Dice::Dice(int n ):faces(n) {
	// TODO Auto-generated constructor stub

}
Dice::Dice():faces(6){

}

Dice::~Dice() {
	// TODO Auto-generated destructor stub
}

 int Dice::throwDice(){
	 srand(time(NULL));
 return (rand() % faces) + 1;
 }
