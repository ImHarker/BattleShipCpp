#pragma once
#include <string>
#include "Board.h"

using namespace std;

class Player {
private:
	string name;
	Board board, boardView;
	int playerN;
public:
	Board &getBoard();
	Board& getBoardView();
};

