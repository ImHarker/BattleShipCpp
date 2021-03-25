#pragma once
#include "Board.h"
class Draw {
private:
	Board boardsPlayer[2];
	Board boardsAI[2];


	void DrawDataLineBoard(int x0, int line, Board board);
	void DrawFirstLineBoard(int x0, Board board);
	void DrawMiddleLineBoard(int x0, Board board);
	void DrawLastLineBoard(int x0, Board board);
	void DrawBoard(int x0, int y0, Board board);
	void DrawCoordLetter(int x0, Board board);

public:
	Draw(Board &player, Board &playerEnemy, Board &AI, Board &AIPlayer);
	void DrawPlayer();
};