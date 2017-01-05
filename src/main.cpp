//============================================================================
// Name        : BoardGames.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Game.h"
#include "SnakesLadders.h"
#include "SnakeManyPions.h"
#include "SnakePedago.h"


using namespace std;

/*void testDice() {
	Dice d(6);

 int r=d.throwDice();
	cout << r << endl;
	r=d.throwDice();
		cout << r << endl;

}

void testBoard(){
	Board b(64);
	b.getcells()[0].affichagecell();
	b.getcells()[63].affichagecell();
	 int s=b.getsize();
	 cout<<s;
}
*/

void testPion(){
	Pion p1;
		cout<<p1.getcellpion()<<endl;
		p1.moveto(5);
		cout<<p1.getcellpion()<<endl;
		p1.moveto(15);
		cout<<p1.getcellpion()<<endl;

}

void testJoueur(){
	Player joueur1("joueur1",true);

	cout<<joueur1.getbot();
	Pion p1;
	p1.moveto(5);

	p1.affichagepion();
	joueur1.getpion(0)->moveto(15);

}


void testGame(){
	Board b(25);
	/*Game jeu(b);
	Player joueur1("joueur1");
	jeu.addPlayer(joueur1);
	jeu.moveplayer(jeu.getplayer(0),13);
	jeu.getplayer(0)->affichageplayer();
	jeu.getplayer(0)->getpion(0)->moveto(0);
	jeu.getplayer(0)->affichageplayer();
	jeu.play();*/
}



void testSnakeLadder(Interface* i){
	//cout<<"début test"<<endl;

	cout<<"board vide"<<endl;
	SnakesLadders s(i);
	cout<<"Jeu crée"<<endl;
	s.initboard();
	cout<<"board initialisé"<<endl;
	s.initplayers();
	cout<<"players initialisés"<<endl;
	s.play();

}


void testSnakeManyPions(Interface* i){
	cout<<"début test"<<endl;
	//Board b(25);
	cout<<"board vide"<<endl;
	SnakeManyPions s(i);
	cout<<"jeu crée"<<endl;
	s.initboard();
	cout<<"board initialisé"<<endl;
	s.initplayers();
	cout<<"players initialisés"<<endl;
	s.play();

}

void testSnakePedago(Interface* i ){
	cout<<"début test"<<endl;

	cout<<"board vide"<<endl;
	SnakePedago s(i);
	cout<<"jeu crée"<<endl;
	s.initboard();
	cout<<"board initialisé"<<endl;
	s.initplayers();
	cout<<"players initialisés"<<endl;
	s.play();
    s.render();
}


int main() {
	Interface interface(sf::VideoMode(800,586) ,"Serpents ou Echelles");
	Interface* i = &interface;

	//interface.setWindow();
	while (interface.isOpen()) {
		//sf::sleep(sf::milliseconds(10)); // Wait 1/100 second
        interface.processEvents();
        // Background color
        //interface.clear(sf::Color(204,206,156));
        interface.render();
		//testSnakeLadders(i);
		//testSnakePedago(i);
		testSnakeManyPions(i);
	}
	return 0;
}

