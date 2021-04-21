#include <iostream>
#include "Game.h"
void Game::GameLoop() {
	Player p;
	AI AI;
	Draw drawManager(p.getBoard(), p.getBoardView(), AI.getBoard(), AI.getBoardView());

	gameover = false;
	gameState = "init";

	while (!gameover) {
		if (gameState == "init") {

			while (1) { //debug
				AI.getBoard().reset(); //debug
				AI.setNShips(0); //debug
				InitGame(p, AI, drawManager);
			} //debug

			}
		system("cls");
		drawManager.DrawPlayer();
	}
}

void Game::InitGame(Player &p, AI &AI, Draw &drawManager) {
	while (AI.getNShips() < 11) {
		system("cls");
		drawManager.DrawBoard(8, 4, AI.getBoard());
		AI.putShip();
		system("cls");
		drawManager.DrawBoard(8, 4, AI.getBoard());
	}

	system("pause"); //debug

	while (p.getNShips() < 11) {
		system("cls");
		drawManager.DrawBoard(8, 4, p.getBoard());
		p.putShip();
		system("cls");
		drawManager.DrawBoard(8, 4, p.getBoard());
	}

	
	gameState = "game";
}

void Game::setGameOver(bool g) {
	gameover = g;
}

bool Game::getGameOver() {
	return gameover;
}
