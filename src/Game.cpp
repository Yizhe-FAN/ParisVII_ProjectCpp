/*
 * Game.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#include "Game.h"

using namespace std;

Game::Game (Interface* i) : board(Board(0)), dice(Dice()) {
	m_interface = i;
}


Game::~Game() {
	// TODO Auto-generated destructor stub
}
void Game::addPlayer(Player p){
players.push_back(p);

}
Player* Game::getplayer(int n){
	list<Player>::iterator it = players.begin();
	advance(it, n);
	return &(*it);

}

 bool Game::isfinished(){
	 bool isfinished=false;
	 for (list<Player>::iterator i = players.begin(), end = players.end(); i != end; ++i) {
		 bool playerfinished=true;
		 for( int j=0;j<(*i).getnumberpions();j++){
			 if (((*i).getpion(j))->getcellpion() !=(board.getsize()-1)){
				 playerfinished=false;
			 }
		 }
		 if(playerfinished){
			 isfinished=playerfinished;
			 cout << "Felicitations! " + (*i).getnameplayer() + " a gagne!!!" <<endl;
			 string temp = "Felicitations! " + (*i).getnameplayer() + " a gagne!!!";
			 m_interface->updateText(temp);
			 render();
		 }
	 }
	 return isfinished;
}


 void Game::moveplayer(Player* p, int n){
	 if (p->getnumberpions()==0){
		 cout<<"ton joueur n'a pas de pion! corrige-moi ce bug fissa!"<<endl;
		 m_interface->updateText("ton joueur n'a pas de pion! corrige-moi ce bug fissa!");
			render();
	 }
	 if (p->getnumberpions()==1){
		 if(p->getpion(0)->getisblocked()){
			 p->getpion(0)->setisblocked(false);
			 cout<<"votre pion n'est plus bloqué"<<endl;
			 m_interface->updateText("votre pion n'est plus bloque");
				render();
		 }
		 else{
	 		this->movepion(p,p->getpion(0), n);
		 }
	 	 }
	 if (p->getnumberpions()>1){
		 int i;
		 if(p->getbot()){
			 i=(rand() % (p->getnumberpions()))+1;
		 }
		 else{
		 cout<<"Quel pion souhaitez-vout déplacer?"<<endl;
		 m_interface->updateText("Quel pion souhaitez-vout deplacer?");
		 render();
		 cin>>i;
		 if (i > (p->getnumberpions())){
			 cout<<"Vous n'avez pas ce pion, quel pion souhaitez-vout déplacer?"<<endl;
			 		 m_interface->updateText("Vous n'avez pas ce pion, quel pion souhaitez-vout déplacer?");
			 		 render();
			 		 cin>>i;
		 	 }
		 }
		 if(p->getpion(i-1)->getisblocked()){
			 for( int j=0 ;j< p->getnumberpions();++j){
			 			 p->getpion(j)->setisblocked(false);
			 }
			 cout<<"Vous avez choisi un pion bloqué, vous passez votre tour"<<endl;
			 m_interface->updateText("Vous avez choisi un pion bloque, vous passez votre tour");
			 render();
		 }
		 else{
			 for( int j=0 ;j< p->getnumberpions();++j){
			 			 p->getpion(j)->setisblocked(false);
			 }
			 cout<<"le joueur a choisi son pion "<<i<<endl;
			 m_interface->updateText("le joueur a choisi son pion ", i);
			 render();
			 this->movepion(p,p->getpion(i-1), n);
		 }


	 	 }
 }

 void Game::movepion(Player* pl,Pion* p, int n){
	int i=p->getcellpion()+n;
	int s=board.getsize()-1;
	if(i<0){
		p->moveto(0);
		cout<<"on ne va pas avant début!"<<endl;
		m_interface->updateText("on ne va pas avant debut!");
		render();
	}
	else if(i>s){
		int r=(2*s)+n-(2*i);
		movepion(pl, p, r);
	}
	else{
		p->moveto(i);
		cout<<"le pion de "<<pl->getnameplayer() <<" se déplace sur la case "<<i<<endl;
		string temp = "le pion de " + pl->getnameplayer() + " se deplace sur la case " ;
		m_interface->updateText(temp, i);
		render();
		//m_interface->updatePion(p->getPionSprite(),i);
		int status=board.getcell(i-1)->getstatus();
		int effect=board.getcell(i-1)->geteffect();
		if(effect!=0){
			cout<<"serpent ou echelle"<<endl;
			m_interface->updateText("serpent ou echelle !!!");
			render();
			movepion(pl,p,effect);
		}
		else if (status==-1){
			p->setisblocked(true);
			cout<<"le pion de "<<pl->getnameplayer() <<" est bloqué sur la case "<<i<<endl;
			temp = "le pion de " + pl->getnameplayer() + " est bloqué sur la case ";
			m_interface->updateText(temp, i);
			render();
		}
		else if (status==1){
			cout<<"le pion de "<<pl->getnameplayer() <<" est sur la case "<<i<< " vous rejouez"<<endl;
			temp = "le pion de " + pl->getnameplayer() + " est sur la case " ;
			m_interface->updateText(temp, i);
			render();
			m_interface->updateText(" vous rejouez");
			render();
			turnplayer(pl);
		}
	}
 }
 bool Game::testtour(Player p){
	 return true;
 }

void Game::play(){
	if(players.size()==0){
		cout<<"pas de jeu sans joueurs"<<endl;
		m_interface->updateText("pas de jeu sans joueurs");
		render();
	}
	else{
		while(this->isfinished()==false){
			unsigned int k=0;
			while( k<players.size()){
				turnplayer(this->getplayer(k));
				k=k+1;
			}
		}
	}
}

void Game::turnplayer(Player* p){
	cout<<" -------- tour de "<<(*p).getnameplayer() << "--------"<<endl;
	string s =" -------- tour de " +  (*p).getnameplayer() + "--------";
	m_interface->updateText(s);
	render();
	bool test=testtour(*p);
	if(test){
		int n=dice.throwDice();
		cout << "Ton dé est " << n << endl;
		m_interface->updateDice(n);
		render();
		moveplayer(p,n);
	}
	else {
		cout<<" tu as raté le test, passe ton tour"<<endl;
		m_interface->updateText(" tu as rate le test, passe ton tour ");
		render();
	}
cout<<"fin du tour"<<endl;
m_interface->updateText("-------- fin du tour --------");
render();
}

void Game::render(){
	m_interface->processEvents();
	    // Background color
	   m_interface->clear(sf::Color(204,206,156));
	   m_interface->setSprite(&(m_interface->backgroundSprite),  m_interface->xboard, m_interface->yboard);
	   m_interface->setSprite(&(m_interface->diceSprite), m_interface->xDice, m_interface->yDice);
	   m_interface->setText(&(m_interface->totalText),m_interface->xText,  m_interface->yText);
	   unsigned k = 0;
	   	while ( k < players.size()){
	   		Player*  p= this->getplayer(k);
	   		for( int j=0 ;j< p->getnumberpions();++j){
	   			Pion* pi = p->getpion(j);
	   			sf::Sprite s = pi->getPionSprite();
	   			m_interface->updatePion(s, (pi->getPionText()),(pi->getcellpion()), k, j, (p->getcolorarry()));
	   		}
	   		k=k+1;
	   	}
	  // Make update visible
	  m_interface->display();
	  sleep(1);
}

void Game::updatecellbusy(int n){
	bool isthisbusy = false;
	unsigned k =0;
	while(k< players.size()){
		Player* p = this->getplayer(k);
		for ( int j=0 ;j< p->getnumberpions();++j){
			Pion* pi = p->getpion(j);
			if(pi->getcellpion()==n){
				isthisbusy = true;
			}
		}
		k = k+1;
	}
this->board.getcell(n)->setisbusy(isthisbusy);
}







