/*
 * SnakePedago.cpp
 *
 *  Created on: 31 déc. 2015
 *      Author: philippe
 */

#include "SnakePedago.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

SnakePedago::SnakePedago(Interface* i): Game(i) {

}

SnakePedago::~SnakePedago() {
	// TODO Auto-generated destructor stub
}


void SnakePedago::initboard(){
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

void SnakePedago::initplayers(){
cout<<"Combien de joueurs humains dans cette partie?"<<endl;
m_interface->updateText("Combien de joueurs humains dans cette partie?");
render();
int n;
cin>>n;
for(int i=0; i<n;i++){
	cout<<"Rentrez le nom du joueur "<<i+1<<endl;
	int temp = i+1;
	m_interface->updateText("Rentrez le nom du joueur ", temp);
	render();
	string name;
	cin>>name;
	Player p(name,false);
	addPlayer(p);
}
cout<<"Combien de joueurs controles par l'ia dans cette partie?"<<endl;
m_interface->updateText("Combien de joueurs controles par l'ia dans cette partie?");
render();
cin>>n;
for(int i=0; i<n;i++){
	cout<<"Rentrez le nom du joueur bot "<<i+1<<endl;
	int temp = i+1;
	m_interface->updateText("Rentrez le nom du joueur bot ", temp);
	render();
	string name;
	cin>>name;
	Player p(name,true);
	addPlayer(p);
}

}
bool SnakePedago::testtour(Player p){
	srand(time(NULL));
	bool result=false;
	if(p.getbot()==true){

		result=rand()%2;
	}
	else{

	int a=rand() % 20;
	int b=rand() % 20;
	int c=(rand() % 3) +1;
	int s;
	switch (c) {

	case 1:
	 cout<<"combien font "<<a<<"+"<<b<<endl;
	 m_interface->updateText("combien font ",  " + " , a,  b);
	 render();
	 cin>>s;
	 if(s==a+b){
		 result=true;
	 }
	 break;
	case 2:
		cout<<"combien font "<<a<<"-"<<b<<endl;
		 m_interface->updateText("combien font ", " - ", a, b);
		 render();
		cin>>s;
			 if(s==a-b){
				 result=true;
			 }
		 break;
	case 3:
		cout<<"combien font "<<a<<"*"<<b<<endl;
		m_interface->updateText("combien font " ," * ", a , b);
		render();
		cin>>s;
			 if(s==a*b){
				 result=true;
			 }
		 break;
	}
	}
	return result;
}


