/*
 * Player.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
pions.push_back(Pion());
numberpions=1;
bot=false;
for (int i = 0 ; i< 3; i++){
	color[i] = rand()%256;
}
}

Player::Player(string s,bool b) {
pions.push_back(Pion());
numberpions=1;
nameplayer=s;
bot=b;
for (int i = 0 ; i< 3; i++){
	color[i] = rand()%256;
}
}

Player::Player(string s, int n, bool b){
	for(int i =0;i<n;i++){
		pions.push_back(Pion());
	}
numberpions=n;
nameplayer=s;
bot=b;
for (int i = 0 ; i< 3; i++){
	color[i] = rand()%256;
}
//color[3] = {rand()%256, rand()%256, rand()%256};
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

string Player::getnameplayer(){
	return nameplayer;
}
/*vector<Pion>  Player::getpions() const {
	return pions;
}*/
vector<Pion>  Player::getpions() {
	return pions;
}
Pion*  Player::getpion(int n) {
	return &pions[n];
}
bool Player::getbot() {
	return bot;
}

int Player::getnumberpions() const{
	return numberpions;
}
void Player::affichageplayer(){
	cout<<"ce joueur a pour nom "<<nameplayer<<endl;
	cout<<"et pour pions: "<<endl;
	for(int i= 0; i<numberpions;++i){
		pions[i].affichagepion();
	}

}

int (&Player::getcolorarry())[3]{
		return color;
}

