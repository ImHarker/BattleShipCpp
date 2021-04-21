#pragma once
#include <string>
#include "Board.h"
#include "Ship.h"
using namespace std;

class Player {
private:
	string name;
	string moves[100];
	Board board, boardView;
	Ship ships[11];
	int playerN;
	int shots;
	int nShips;
public:
	Player();
	~Player();

	void putShip();


	void setName(string n);
	void setBoard(Board b);
	void setBoardView(Board bv);
	void setPlayerN(int n);
	void setShots(int n);
	void setNShips(int n);
	void setShips(Ship sh);

	string getName();
	int getPlayerN();
	int getShots();
	Board &getBoard();
	Board& getBoardView();
	int getNShips();
	Ship getShip(int n);
	bool isAdjacent(int x, int y);

};

