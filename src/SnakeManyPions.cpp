/*
 * SnakeManyPions.cpp
 *
 *  Created on: 31 déc. 2015
 *      Author: philippe
 */

#include "SnakeManyPions.h"

#include <iostream>
using namespace std;

SnakeManyPions::SnakeManyPions(Interface* i) :Game(i) {

}

SnakeManyPions::~SnakeManyPions() {
	// TODO Auto-generated destructor stub
}

void SnakeManyPions::initboard(){
	Board b (65);

b.getcell(2)->seteffect(15);
b.getcell(15)->setstatus(1);
b.getcell(18)->seteffect(-14);
b.getcell(23)->seteffect(15);
b.getcell(26)->seteffect(-19);
b.getcell(28)->seteffect(24);
b.getcell(42)->setstatus(-1);
b.getcell(47)->seteffect(15);
b.getcell(51)->setstatus(-1);
b.getcell(57)->seteffect(-17);
b.getcell(58)->setstatus(1);
b.getcell(61)->seteffect(-30);
	board=b;
}

void SnakeManyPions::initplayers(){
	cout<<"Combien de pions par joueur dans cette partie?"<<endl;
	m_interface->updateText("Combien de pions par joueur dans cette partie?");
	render();
	int nombrepions;
	cin>>nombrepions;
    cout<<"Combien de joueurs humains dans cette partie?"<<endl;
    m_interface->updateText("Combien de joueurs humains dans cette partie?");
	render();
    int n;
    cin>>n;

    for(int i=0; i<n;i++){
    	cout<<"Rentrez le nom du joueur "<<i+1<<endl;
    	int temp = i + 1;
    	m_interface->updateText("Rentrez le nom du joueur ", temp);
    	render();
    	string name;
	    cin>>name;
	    Player p(name,nombrepions,false);
	    addPlayer(p);
    }
    cout<<"Combien de joueurs controles par l'ia dans cette partie?"<<endl;
    m_interface->updateText("Combien de joueurs controles par l'ia dans cette partie?");
	render();
    cin>>n;

    for(int i=0; i<n;i++){
    	cout<<"Rentrez le nom du joueur bot "<<i+1<<endl;
    	int temp = i + 1;
    	m_interface->updateText("Rentrez le nom du joueur bot ", temp);
    	render();
	    string name;
	    cin>>name;
	    Player p(name,nombrepions,true);
	    addPlayer(p);
    }
}

