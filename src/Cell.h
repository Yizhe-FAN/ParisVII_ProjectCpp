/*
 * Cell.h
 *
 *  Created on: 15 déc. 2015
 *      Author: philippe
 */

#ifndef CELL_H_
#define CELL_H_

class Cell {
public:
	Cell();
	virtual ~Cell();
	int geteffect();
	int getstatus();
	void seteffect(int n);
	void setstatus(int n);
	bool getisbusy();
	void setisbusy(bool b);
	void affichagecell();
protected:
	        int effectcell;//indique le déplacement qu'entraine la case(négatif si serpent, positif si échelle)
			int statuscell; //si =0, la case ne fait rien, si =1, la case permet de rejouer,s=-1 le joeur passera le prochain tour
			bool isbusy;
};

#endif /* CELL_H_ */
