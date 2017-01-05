/*
 * Pion.h
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#ifndef PION_H_
#define PION_H_
#include "Cell.h"
#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>

class Pion {
public:
	Pion();
	virtual ~Pion();
	 void moveto(int n);
	 int getcellpion();
	 bool getisblocked();
	 void setisblocked(bool b);
	 void affichagepion();
	 sf::Sprite& getPionSprite();
	 sf::Text& getPionText();

protected:
	int cellpion;
	bool isblocked;
	 sf::Texture m_texture;
	 sf::Sprite m_sprite;
	 sf::Text m_text;
};

#endif /* PION_H_ */
