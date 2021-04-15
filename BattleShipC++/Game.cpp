#include <iostream>
#include "Game.h"
void Game::GameLoop() {
	Player p;
	AI AI;
	Draw drawManager(p.getBoard(), p.getBoardView(), AI.getBoard(), AI.getBoardView());
	std::cout << "Welcome To BattleShip" << std::endl;
	p.getBoard().setMatrixCell(2, 2, 'O');
	p.getBoard().setMatrixCell(10, 10, 'O');

	drawManager.DrawPlayer();
}
