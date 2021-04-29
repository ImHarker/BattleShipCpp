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

void Player::play(Player &enemy, Draw drawManager, int turns) {
	NavalCoordinate move;
	system("cls");
	if (getNMoves() == 99) {
		setAmmo(1);
	} else {
		setAmmo(3);
	}

	while (getAmmo() > 0 && getNShips() > 0) {
		system("cls");
		drawManager.DrawScore(turns, getNShips(), enemy.getNShips());
		cout << "Your Turn";
		drawManager.DrawPlayer(); // Player + Player moves
		cout << endl;
		move.ask2Set();

		system("cls");
		drawManager.DrawScore(turns, getNShips(), enemy.getNShips());
		cout << "Your Turn";
		drawManager.DrawPlayer(); // Player + Player moves
		cout << endl << "Shooting (" << move.getX() << "," << move.getY() << ")!" << endl;
		Sleep(2500);

		playMove(move.getIntX(), move.getY(), enemy, drawManager, turns);

	}
}

void Player::playMove(int x, int y, Player& enemy, Draw drawManager, int turns) {
	int i, j;
	NavalCoordinate move;
	for (i = 0; i < 100; i++) {
		if (x == getMove(i).getIntX() && y == getMove(i).getY()) { 
			if (enemy.getName() == "AI") {
				cout << "You already played in this coordinate!" << endl;
				Sleep(1500);
			} else {
				cout << "Already played in this coordinate! Retrying..." << endl;
				Sleep(1500);
			}
			return;
		}
	}
		
	for (j = 0; j < 11; j++) {
				if (x == enemy.getShip(j)->getLocation().getIntX() && y == enemy.getShip(j)->getLocation().getY()) {
					move.setX(x);
					move.setY(y);
					move.setC('T');
					enemy.getBoard().setMatrixCell(move);
					enemy.getShip(j)->hit();
					getBoardView().setMatrixCell(move);
					setMoves(move);

					if (enemy.getName() == "AI") {
						system("cls");
						drawManager.DrawScore(turns, getNShips(), enemy.getNShips());
						cout << "Your Turn";
						drawManager.DrawPlayer();
					} else {
						system("cls");
						drawManager.DrawScore(turns, enemy.getNShips(), getNShips());
						cout << "AI Turn" << endl << "Your board";
						drawManager.DrawBoard(8, 2, getBoardView());
					}
					cout << endl << "Successfully shot at (" << (char)(x + 64) << "," << y << ") and hit a ship!" << endl;

					if (enemy.getShip(j)->integrity()) {
						enemy.setNShips(enemy.getNShips() - 1);
						if (enemy.getNShips() == 0) {
							cout << "Last ship destroyed!" << endl;
						}else
							cout << "Ship destroyed! " << enemy.getNShips() << " remaining" << endl;
					}
					setNMoves(getNMoves() + 1);
					setAmmo(getAmmo() - 1);
					Sleep(2500);
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
					if (enemy.getName() == "AI") {
						system("cls");
						drawManager.DrawScore(turns, getNShips(), enemy.getNShips());
						cout << "Your Turn";
						drawManager.DrawPlayer();
					} else {
						system("cls");
						drawManager.DrawScore(turns, enemy.getNShips(), getNShips());
						cout << "AI Turn" << endl << "Your board";
						drawManager.DrawBoard(8, 2, getBoardView());
					}
					cout << endl << "Successfully shot at (" << (char)(x + 64) << "," << y << "), but it was water!" << endl << endl;
					Sleep(2500);
					return;
		}
	}
}

std::ostream& operator<<(std::ostream& os, Player &p) {
	int i;
	os << p.name << ";";
	os << std::endl;
	for (i = 0; i < 100; i++) {
		os << p.moves[i];
	}
	os << std::endl;
	os << p.board;
	os << p.boardView;
	for (i = 0; i < 11; i++) {
		os << *p.ships[i];
	}

	os << p.nMoves << ";" << p.playerN << ";" << p.ammo << ";" << p.nShips << ";";
	
	return os;
}
