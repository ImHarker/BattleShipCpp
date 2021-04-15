#pragma once
#include <string>
#include "Board.h"

using namespace std;

class Player {
private:
	string name;
	string moves[100];
	Board board, boardView;
	int playerN;
	int shots;
public:
	Player();
	~Player();

	void setName(string n);
	void setBoard(Board b);
	void setBoardView(Board bv);
	void setPlayerN(int n);
	void setShots(int n);

	string getName();
	int getPlayerN();
	int getShots();
	Board &getBoard();
	Board& getBoardView();
	
};

