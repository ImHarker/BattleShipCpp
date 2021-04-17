#pragma once
#include "Board.h"
class Draw {
private:
	Board *boardsPlayer[2];
	Board *boardsAI[2];


	void DrawDataLineBoard(int x0, int line, Board board);
	void DrawFirstLineBoard(int x0, Board board);
	void DrawMiddleLineBoard(int x0, Board board);
	void DrawLastLineBoard(int x0, Board board);
	void DrawCoordLetter(int x0, Board board);
	void DrawBoards(Board board, Board board2, int x0, int y0);

public:
	Draw(Board &player, Board &playerEnemy, Board &AI, Board &AIPlayer);
	void DrawBoard(int x0, int y0, Board board);
	void DrawPlayer();
	void DrawAI();

	static void Menu();
};