/*
 * Interface.cpp
 *
 *  Created on: 2016年1月1日
 *      Author: yzfan
 */

#include "Interface.h"
#include<iostream>
#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>

using namespace std;

Interface::Interface(sf::VideoMode mode, const std::string& title): sf::RenderWindow(mode, title){
	  text_total = "Welcome";
	  // Load images in textures and create sprite
	  // background sprite
	  if (!backgroundTexture.loadFromFile("Board.jpg")) {
	    cerr << "Error loading Board.jpg" << endl;
	    exit(0);
	  }
	  backgroundSprite.setTexture(backgroundTexture);

	  /* Pion sprite
	  if (!pionTexture.loadFromFile("Red.png")) {
	    cerr << "Error loading Red.png" << endl;
	    exit(0);
	  }
	  pionSprite.setTexture(pionTexture);
      */

	  if(!diceTexture.loadFromFile("Dice_1.png")){
		  cerr << "Error loading Dice_1.png" <<endl;
		  exit(0);
	  }
	  diceSprite.setTexture(diceTexture);

	  if(!totalFont.loadFromFile("a010015l.pfb")){
		  cerr << "Error loading a010015l.pfb" <<endl;
		  exit(0);
	  }
	  totalText.setFont(totalFont);

}

Interface::~Interface() {
	// TODO Auto-generated destructor stub
}

/*bool Interface::getWindow(){
	return window.isOpen();
}*/

/*void Interface::setWindow(){
	window.create(sf::VideoMode(800, 586), "Serpents ou Echelles");
}*/

void Interface:: processEvents(){

       	while (pollEvent(event)) {
       		if (event.type == sf::Event::Closed)
       			close();
       	}
}

void Interface::setText(sf::Text* text, int dx, int dy){
	float xpos = dx;
	float ypos = dy;
	text->setPosition(xpos, ypos);
	text->setString(text_total);
	text->setColor(sf::Color(255,255,0));
	text->setStyle(sf::Text::Bold);
	text->setCharacterSize(20);
	draw(*text);
}

void Interface::setSprite(sf::Sprite *sprite, int dx,int dy){
    // Dimensions of the sprite
    //sf::FloatRect rect = sprite->getGlobalBounds();
    // Position of upper-left corner of the sprite
    //float xpos = (xdim - rect.width)  - dx;
    //float ypos = (ydim - rect.height) - dy;
	float xpos = dx;
	float ypos = dy;
    // Set position of the sprite
    sprite->setPosition(xpos, ypos);
    // Draw the sprite at the given position
    draw(*sprite);
}


//Update view
void Interface::render() {
    // Background color
   clear(sf::Color(204,206,156));
    setSprite(&backgroundSprite,xboard, yboard);
    setSprite(&diceSprite,xDice,yDice);
    setText(&totalText,xText, yText);
    //setSprite(&pionSprite,xPion,yPion);
   // Make update visible
  display();
  sleep(1);
}

void Interface::updateDice(int n){
	switch(n)
	{
	case 1:
		if(!diceTexture.loadFromFile("Dice_1.png")){
				  cerr << "Error loading Dice_1.png" <<endl;
				  exit(0);
			  }
			  diceSprite.setTexture(diceTexture);break;
	case 2:
		if(!diceTexture.loadFromFile("Dice_2.png")){
				cerr << "Error loading Dice_2.png" <<endl;
				exit(0);
			 }
			 diceSprite.setTexture(diceTexture);break;
	case 3:
			if(!diceTexture.loadFromFile("Dice_3.png")){
				cerr << "Error loading Dice_3.png" <<endl;
				 exit(0);
			 }
			 diceSprite.setTexture(diceTexture);break;
	case 4:
			if(!diceTexture.loadFromFile("Dice_4.png")){
				cerr << "Error loading Dice_4.png" <<endl;
				exit(0);
			 }
			 diceSprite.setTexture(diceTexture);break;
	case 5:
			if(!diceTexture.loadFromFile("Dice_5.png")){
				cerr << "Error loading Dice_5.png" <<endl;
				 exit(0);
				 }
			diceSprite.setTexture(diceTexture);break;
	case 6:
			if(!diceTexture.loadFromFile("Dice_6.png")){
				cerr << "Error loading Dice_6.png" <<endl;
			   exit(0);
				 }
			 diceSprite.setTexture(diceTexture);break;
	default: cout << "match failed" << endl;
	}
	//render();
}

 void Interface::updatePion(sf::Sprite& pionSprite, sf::Text& pionText, const int& c, const int& n_pl, const int& n_p, int(& color)[3]) {
	/* if(!m_font.loadFromFile("a010015l.pfb")){
	 		cerr << "Error loading a010015l.pfb" <<endl;
	 		exit(0);
	 }*/
	 pionText.setFont(totalFont);
	 strstream ss;
	 string s;
	 ss << n_p + 1;
	 ss >>s;
	 pionText.setString(s);
	 pionText.setColor(sf::Color(color[2],color[2],color[2]));
	 pionText.setStyle(sf::Text::Bold);
	 pionText.setCharacterSize(16);
	 pionSprite.setColor(sf::Color(color[0],color[1],color[2]));

	 sf::Vector2f pos = pionSprite.getPosition();
	int a = c % 8 ;
	int b = c / 8 ;
	int k = b % 2 ;
	if ( a == 0 ){
		if (b == 0){
			pos.x = 145;
			pos.y = 536;
		}
		else {
			if (k == 0){
				pos.x = x[a];
				pos.y = y[b-1];
			}
			else
			pos.x = x_inverse[a];
			pos.y = y[b-1];
		}
	}
	else{
		if (k == 0){
			pos.x = x[a-1];
			pos.y = y[b];
		}
			else
				pos.x = x_inverse[a-1];
				pos.y = y[b];
	}

	if (!c){
		pos.y -= n_pl* 30;
		pos.x +=n_p * 30;
	}
	else{
	pos.y -= n_pl *7 ;
	pos.x += n_p *7 ;
	}
	setSprite(&pionSprite, pos.x, pos.y);
	pionText.setPosition(pos.x,pos.y);
	draw(pionText);
}

 /*void Interface::afficherPion(sf::Sprite& pionSprite){
	    draw(pionSprite);
	    display();
 }
*/

void Interface::updateText(const string& s){
	text_total = s ;
    //render();
}

void Interface::updateText(const string&s, int& n){
	strstream ss;
	string m_s;
	ss << n;
	ss >> m_s;
	text_total = s + m_s;
	//render();
}

void Interface::updateText(const std::string& s1, const std::string& s2, int& a, int& b){
	strstream sn1, sn2 ;
	string m_s1, m_s2;
	sn1 << a;
	sn1 >> m_s1;
	sn2 << b;
	sn2 >> m_s2;
	text_total = s1 + m_s1 + s2 + m_s2;
	//render();
}

