#include "AI.h"
#include "Submarine.h"
#include <iostream>
#include <math.h>


AI::AI() : Player(){

}

AI::~AI() {
}

void AI::putShip() {
	Submarine *sub = new Submarine;
	//Submarine sub;
	int x, y;

	//checks collision
	do{
	x = rand() % 10 + 1;
	y = rand() % 10 + 1;
	}while (isAdjacent(x,y));

		sub->getLocation().setX(x);
		sub->getLocation().setY(y);
		sub->getLocation().setC('O');
		getBoard().setMatrixCell(sub->getLocation());
		setShips(sub);
		setNShips(getNShips() + 1);
	
}
