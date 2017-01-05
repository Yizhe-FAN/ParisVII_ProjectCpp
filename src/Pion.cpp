/*
 * Pion.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#include "Pion.h"
#include <iostream>
using namespace std;

Pion::Pion(): cellpion(0),isblocked(false) {

	if (!m_texture.loadFromFile("Red.png")) {
		cerr << "Error loading Red.png" << endl;
	    exit(0);
	}
	m_sprite.setTexture(m_texture);



}

Pion::~Pion() {
	// TODO Auto-generated destructor stub
}

 void Pion::moveto(int n) {
	cellpion=n;
}

 int Pion::getcellpion() {
	 return cellpion;
 }
 bool Pion::getisblocked(){
	 return isblocked;
 }
 void Pion::setisblocked(bool b){
	 isblocked=b;
 }
 void Pion::affichagepion(){
	 cout<<"ce pion est sur la case "<<cellpion<<endl;
 }
sf::Sprite& Pion::getPionSprite(){
	return m_sprite;
}
sf::Text& Pion::getPionText(){
	return m_text;
}
