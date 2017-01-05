/*
 * Interface.h
 *
 *  Created on: 2016年1月1日
 *      Author: yzfan
 */

#ifndef SRC_INTERFACE_H_
#define SRC_INTERFACE_H_

#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<strstream>
#include <unistd.h>

class Interface: public sf::RenderWindow {
public:
	Interface(sf::VideoMode mode, const std::string& title);
	virtual ~Interface();

	void setSprite(sf::Sprite *, int dx, int dy);
	void setText(sf::Text*, int dx, int dy);
	//bool getWindow();
	//void setWindow();
	void processEvents();
	void render();

	//void afficherPion(sf::Sprite& pionSprite);
	void updateDice(int n);
    void updatePion(sf::Sprite& pionSprite, sf::Text& pionText, const int& c, const int&n_pl, const int&n_p, int(& color)[3]);		        // Update positions of pion
    void updateText(const std::string& s);
    void updateText(const std::string&s, int& n);
    void updateText(const std::string& s1, const std::string& s2, int&a, int& b);


//private:
        //std::vector<sf::Texture> pionTextures;
        //std::vector<sf::Sprite> pionSprites;
         // sf::RenderWindow window;	// Main window
         sf::Event event;
         sf::Texture backgroundTexture; 	// Texture for the background
         sf::Sprite backgroundSprite;		// background sprite
        // sf::Texture pionTexture;	// Texture for the Pion
        // sf::Sprite pionSprite;	    // Pion sprite
         sf::Texture diceTexture;
         sf::Sprite diceSprite;
         sf::Font totalFont;
         sf::Text totalText;

         //int xPion = 325;                // position x du pion
         //int yPion = 536;                // position y du pion
         const int xdim = 800;		// X dimension of the window
         const int ydim = 586;		// Y dimenion of the window
         const int xboard = 300;
         const int yboard = 50;
         const int xDice = 110;
         const int yDice = 286;
         const int xText = 100;
         const int yText = 16;
         std::string text_total;
         const int x[8] = {310, 370, 430, 490, 550, 610, 670, 730};
         const int y[8] = {546, 486, 426, 366, 306, 246, 186, 126};
         const int x_inverse[8] = {730,670, 610, 550, 490, 430 ,370, 310};
};

#endif /* SRC_INTERFACE_H_ */
