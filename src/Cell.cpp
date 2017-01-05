/*
 * Cell.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#include "Cell.h"
#include <iostream>
using namespace std;


Cell::Cell():effectcell(0),statuscell(0), isbusy(false) {
	// TODO Auto-generated constructor stub

}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

int Cell::geteffect(){
	return effectcell;
}
void Cell::affichagecell(){
	cout<<"cette case a pour effet "<<effectcell<<endl;
}
int Cell::getstatus(){
	return statuscell;
}
void Cell::seteffect(int n){
	effectcell=n;

}
void Cell::setstatus(int n){
statuscell=n;
	}
bool Cell::getisbusy(){
	return isbusy;
}
void Cell::setisbusy(bool b){
	isbusy = b;
}
