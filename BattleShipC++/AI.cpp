#include "AI.h"
#include "Submarine.h"
#include <iostream>
#include <math.h>


AI::AI() : Player(){

}

void AI::putShip() {
	Submarine sub;
	int x, y;
	int i;
	bool adj = false;

	//checks collision
	do{
	x = rand() % 10 + 1;
	y = rand() % 10 + 1;
	if (x == 1) {
		for (i = 0; i < getNShips(); i++) {
			if ((getShip(i).getLocation().getIntX() == x && (getShip(i).getLocation().getY() == y + 1 || getShip(i).getLocation().getY() == y - 1)) || (getShip(i).getLocation().getIntX() == x +1 && (getShip(i).getLocation().getY() == y + 1 || getShip(i).getLocation().getY() == y - 1 || getShip(i).getLocation().getY() == y)) || (getShip(i).getLocation().getIntX() == x && getShip(i).getLocation().getY() == y)) {
				adj = true;
				break;
			} else {
				adj = false;
			}
		}
	}else if (y == 1) {
		for (i = 0; i < getNShips(); i++) {
			if ((getShip(i).getLocation().getY() == y && (getShip(i).getLocation().getIntX() == x + 1 || getShip(i).getLocation().getIntX() == x - 1)) || (getShip(i).getLocation().getY() == y + 1 && (getShip(i).getLocation().getIntX() == x + 1 || getShip(i).getLocation().getIntX() == x - 1 || getShip(i).getLocation().getIntX() == x)) || (getShip(i).getLocation().getIntX() == x && getShip(i).getLocation().getY() == y)) {
				adj = true;
				break;
			} else {
				adj = false;
			}
		}
	}else if (x == 10) {
		for (i = 0; i < getNShips(); i++) {
			if ((getShip(i).getLocation().getIntX() == x && (getShip(i).getLocation().getY() == y + 1 || getShip(i).getLocation().getY() == y - 1)) || (getShip(i).getLocation().getIntX() == x - 1 && (getShip(i).getLocation().getY() == y + 1 || getShip(i).getLocation().getY() == y - 1 || getShip(i).getLocation().getY() == y)) || (getShip(i).getLocation().getIntX() == x && getShip(i).getLocation().getY() == y)) {
				adj = true;
				break;
			} else {
				adj = false;
			}
		}
	}else if (y == 10) {
		for (i = 0; i < getNShips(); i++) {
			if ((getShip(i).getLocation().getY() == y && (getShip(i).getLocation().getIntX() == x + 1 || getShip(i).getLocation().getIntX() == x - 1)) || (getShip(i).getLocation().getY() == y - 1 && (getShip(i).getLocation().getIntX() == x + 1 || getShip(i).getLocation().getIntX() == x - 1 || getShip(i).getLocation().getIntX() == x)) || (getShip(i).getLocation().getIntX() == x && getShip(i).getLocation().getY() == y)) {
				adj = true;
				break;
			} else {
				adj = false;
			}
		}
	} else {
		for (i = 0; i < getNShips(); i++) {
			if ((getShip(i).getLocation().getIntX() == x && (getShip(i).getLocation().getY() == y + 1 || getShip(i).getLocation().getY() == y - 1)) || (getShip(i).getLocation().getY() == y && (getShip(i).getLocation().getIntX() == x + 1 || getShip(i).getLocation().getIntX() == x - 1)) || (getShip(i).getLocation().getIntX() == x + 1 && (getShip(i).getLocation().getY() == y + 1 || getShip(i).getLocation().getY() == y - 1)) || (getShip(i).getLocation().getIntX() == x - 1 && (getShip(i).getLocation().getY() == y + 1 || getShip(i).getLocation().getY() == y - 1)) || (getShip(i).getLocation().getIntX() == x && getShip(i).getLocation().getY() == y)) {
				adj = true;
				break;
			} else {
				adj = false;
			}
		}
	}
	}while (adj);
		sub.getLocation().setX(x);
		sub.getLocation().setY(y);
		sub.getLocation().setC('O');
		getBoard().setMatrixCell(sub.getLocation());
		setShips(sub);
		setNShips(getNShips() + 1);
	
}
