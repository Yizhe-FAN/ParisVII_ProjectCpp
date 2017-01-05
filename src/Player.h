/*
 * Player.h
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <vector>
#include"Pion.h"

class Player {
public:
	Player();
	Player (std::string s,bool b);
	Player (std::string s,int n,bool b);
	virtual ~Player();
	 std::string getnameplayer();
	 /*Pion & at(size_t index) {
	       return pions.at(index);
	    }

	    const Pion & at(size_t index) const {
	       return pions.at(index);
	    }*/
	 //std::vector<Pion> getpions() const ;
	 std::vector<Pion> getpions()  ;
	 Pion*  getpion(int n);
	 bool getbot();
	 int getnumberpions() const;
     int (&getcolorarry())[3];
	 void affichageplayer();
protected :
	std::string nameplayer;
	std::vector<Pion> pions;
	int numberpions;
	bool bot;
    int color[3];
};

#endif /* PLAYER_H_ */
