#include "Board.h"
#include "NavalCoordinate.h"
#include "Player.h"
#include "Draw.h"

#include <iostream>


int main() {
	Player p, AI;
	Draw drawManager(p.getBoard(), p.getBoardView(), AI.getBoard(), AI.getBoardView());
	std::cout << "Welcome To BattleShip" << std::endl;
	p.getBoard().setMatrixCell(2, 2, 'O');
	p.getBoard().setMatrixCell(10, 10, 'O');
	
	drawManager.DrawPlayer();

	return 0;
}