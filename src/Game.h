/*
 * Game.h
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#ifndef GAME_H_
#define GAME_H_
#include "Board.h"
#include "Player.h"
#include "Dice.h"
#include"Interface.h"
#include <list>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

class Game {
public:

	Game(Interface* i);
	virtual ~Game();
	 bool isfinished();
	 void addPlayer(Player p);
	 void moveplayer(Player* p, int n);
	 void movepion( Player* pl,Pion* p, int n);
	 void play();
	 void turnplayer(Player* p);
	 Player* getplayer(int n);
	 bool testtour(Player p);
	 void updatecellbusy(int n);
	 virtual void initboard()=0;
	 virtual void initplayers()=0;
	 void render();

protected:
	Board board;
	std::list<Player> players;
     Dice dice;
    Interface* m_interface;
};

#endif /* GAME_H_ */
