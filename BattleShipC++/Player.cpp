#include "Player.h"



Player::Player() {
	int i;
	name = "";
    playerN = 0;
    ammo = 3;
    nShips = 0;
	nMoves = 0;
	for (i = 0; i < 11; i++) {
		ships[i] = NULL;
	}
	for (i = 0; i < 100; i++) {
		moves[i] = NavalCoordinate(0, 0, '.');
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

void Player::setAmmo(int n) {
    ammo = n;
}

void Player::setNShips(int n) {
    nShips = n;
}

void Player::setShips(Ship *sh) {
    ships[nShips] = sh;
}

void Player::setNMoves(int n) {
	nMoves = n;
}

void Player::setMoves(NavalCoordinate move) {
	moves[nMoves] = move;
}

string Player::getName() {
    return name;
}

int Player::getPlayerN() {
    return playerN;
}

int Player::getAmmo() {
    return ammo;
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

bool Player::isAdjacent(int x, int y) { //Refactor needed to handle other ships... Only works for submarines
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

int Player::getNMoves() {
	return nMoves;
}

NavalCoordinate Player::getMove(int n) {
	return moves[n];
}

void Player::play(Player &enemy, Draw drawManager) {
	system("cls");
	cout << "Player Turn" << endl;
	system("pause");
}

void Player::playMove(int x, int y, Player& enemy) {
	int i, j;
	NavalCoordinate move;
	for (i = 0; i < 100; i++) {
		if (x == getMove(i).getIntX() && y == getMove(i).getY()) return;
	}
		
	for (j = 0; j < 11; j++) {
				if (x == enemy.getShip(j)->getLocation().getIntX() && y == enemy.getShip(j)->getLocation().getY()) {
					move.setX(x);
					move.setY(y);
					move.setC('T');
					enemy.getBoard().setMatrixCell(move);
					enemy.setNShips(enemy.getNShips() - 1); //Refactor to different ships
					getBoardView().setMatrixCell(move);
					setMoves(move);
					setNMoves(getNMoves() + 1);
					setAmmo(getAmmo() - 1);
					return;
				}else if(j == 10){
					move.setX(x);
					move.setY(y);
					move.setC('A');
					enemy.getBoard().setMatrixCell(move);
					getBoardView().setMatrixCell(move);
					setMoves(move);
					setNMoves(getNMoves() + 1);
					setAmmo(getAmmo() - 1);
					return;
		}
	}
}
