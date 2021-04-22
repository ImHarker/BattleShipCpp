#include "Player.h"
#include "Submarine.h"


Player::Player() {
	int i;
	name = "";
    playerN = 0;
    shots = 3;
    nShips = 0;
	for (i = 0; i < 11; i++) {
		ships[i] = NULL;
	}
}

Player::~Player() {
	int i;
	for (i = 0; i < 11; i++) {
		if(ships[i] != NULL)
		delete ships[i];
	}
}

void Player::putShip() {
    Submarine *sub = new Submarine;
    cout << endl << endl;
	do {
		sub->getLocation().ask2Set();
		if (isAdjacent(sub->getLocation().getIntX(), sub->getLocation().getY())) cout << "Invalid position (" << sub->getLocation().getX() << sub->getLocation().getY() <<"): Adjacent Ships!" << endl;
	} while (isAdjacent(sub->getLocation().getIntX(), sub->getLocation().getY()));
	sub->getLocation().setC('O');
    getBoard().setMatrixCell(sub->getLocation());
    ships[nShips] = sub;
    nShips++;
}

void Player::setName(string n) {
    name = n;
}

void Player::setBoard(Board b) {
    board = b;
}

void Player::setBoardView(Board bv) {
    boardView = bv;
}

void Player::setPlayerN(int n) {
    playerN = n;
}

void Player::setShots(int n) {
    shots = n;
}

void Player::setNShips(int n) {
    nShips = n;
}

void Player::setShips(Ship *sh) {
    ships[nShips] = sh;
}

string Player::getName() {
    return name;
}

int Player::getPlayerN() {
    return playerN;
}

int Player::getShots() {
    return shots;
}

Board &Player::getBoard() {
    return board;
}

Board& Player::getBoardView() {
    return boardView;
}

int Player::getNShips() {
    return nShips;
}

Ship *Player::getShip(int n) {
    return ships[n];
}

bool Player::isAdjacent(int x, int y) {
    bool adj = false;
	int i;
	if (x == 1) {
		for (i = 0; i < getNShips(); i++) {
			if ((getShip(i)->getLocation().getIntX() == x && (getShip(i)->getLocation().getY() == y + 1 || getShip(i)->getLocation().getY() == y - 1)) || (getShip(i)->getLocation().getIntX() == x + 1 && (getShip(i)->getLocation().getY() == y + 1 || getShip(i)->getLocation().getY() == y - 1 || getShip(i)->getLocation().getY() == y)) || (getShip(i)->getLocation().getIntX() == x && getShip(i)->getLocation().getY() == y)) {
				adj = true;
				break;
			} else {
				adj = false;
			}
		}
	} else if (y == 1) {
		for (i = 0; i < getNShips(); i++) {
			if ((getShip(i)->getLocation().getY() == y && (getShip(i)->getLocation().getIntX() == x + 1 || getShip(i)->getLocation().getIntX() == x - 1)) || (getShip(i)->getLocation().getY() == y + 1 && (getShip(i)->getLocation().getIntX() == x + 1 || getShip(i)->getLocation().getIntX() == x - 1 || getShip(i)->getLocation().getIntX() == x)) || (getShip(i)->getLocation().getIntX() == x && getShip(i)->getLocation().getY() == y)) {
				adj = true;
				break;
			} else {
				adj = false;
			}
		}
	} else if (x == 10) {
		for (i = 0; i < getNShips(); i++) {
			if ((getShip(i)->getLocation().getIntX() == x && (getShip(i)->getLocation().getY() == y + 1 || getShip(i)->getLocation().getY() == y - 1)) || (getShip(i)->getLocation().getIntX() == x - 1 && (getShip(i)->getLocation().getY() == y + 1 || getShip(i)->getLocation().getY() == y - 1 || getShip(i)->getLocation().getY() == y)) || (getShip(i)->getLocation().getIntX() == x && getShip(i)->getLocation().getY() == y)) {
				adj = true;
				break;
			} else {
				adj = false;
			}
		}
	} else if (y == 10) {
		for (i = 0; i < getNShips(); i++) {
			if ((getShip(i)->getLocation().getY() == y && (getShip(i)->getLocation().getIntX() == x + 1 || getShip(i)->getLocation().getIntX() == x - 1)) || (getShip(i)->getLocation().getY() == y - 1 && (getShip(i)->getLocation().getIntX() == x + 1 || getShip(i)->getLocation().getIntX() == x - 1 || getShip(i)->getLocation().getIntX() == x)) || (getShip(i)->getLocation().getIntX() == x && getShip(i)->getLocation().getY() == y)) {
				adj = true;
				break;
			} else {
				adj = false;
			}
		}
	} else {
		for (i = 0; i < getNShips(); i++) {
			if ((getShip(i)->getLocation().getIntX() == x && (getShip(i)->getLocation().getY() == y + 1 || getShip(i)->getLocation().getY() == y - 1)) || (getShip(i)->getLocation().getY() == y && (getShip(i)->getLocation().getIntX() == x + 1 || getShip(i)->getLocation().getIntX() == x - 1)) || (getShip(i)->getLocation().getIntX() == x + 1 && (getShip(i)->getLocation().getY() == y + 1 || getShip(i)->getLocation().getY() == y - 1)) || (getShip(i)->getLocation().getIntX() == x - 1 && (getShip(i)->getLocation().getY() == y + 1 || getShip(i)->getLocation().getY() == y - 1)) || (getShip(i)->getLocation().getIntX() == x && getShip(i)->getLocation().getY() == y)) {
				adj = true;
				break;
			} else {
				adj = false;
			}
		}
	}
	return adj;
}
