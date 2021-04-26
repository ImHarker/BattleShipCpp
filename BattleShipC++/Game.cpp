#include "Game.h"
#include <Windows.h>
#include <iostream>
#include <math.h>
void Game::GameLoop() {
	Player p;
	AI AI;
	Draw drawManager(p.getBoard(), p.getBoardView(), AI.getBoard(), AI.getBoardView());

	p.setPlayerN(rand() % 2 + 1);
	if (p.getPlayerN() == 1) {
		AI.setPlayerN(2);
	} else {
		AI.setPlayerN(1);
	}

	turns = 0;
	gameover = false;
	gameState = "init";

	while (!gameover) {
#pragma region INIT
		if (gameState == "init") {
				InitGame(p, AI, drawManager);
			}
#pragma endregion

		if (p.getPlayerN() == 1) {
			turns++;
			p.play(AI, drawManager);
			if (AI.getNShips() == 0) {
				gameover = true;
				break;
			}
			AI.play(p, drawManager);
			if (p.getNShips() == 0) {
				gameover = true;
				break;
			}
		} else {
			turns++;
			AI.play(p, drawManager);
			if (p.getNShips() == 0) {
				gameover = true;
				break;
			}
			p.play(AI, drawManager);
			if (AI.getNShips() == 0) {
				gameover = true;
				break;
			}
		}

		//DEBUG
		//system("cls");
		//cout << "AI" << AI << endl;
		//cout << "Player" << p << endl;
		//cout << "Game Data" << endl << *this << endl;
		//system("pause"); //debug 
	}

	if (p.getNShips() == 0) {
		system("cls");
		cout << "AI WON! with " << AI.getNMoves() << " shots taken in " << turns << " turns! The player shot " << p.getNMoves() << " times" << endl;
	} else {
		cout << "Player WON! with " << p.getNMoves() << " shots taken in " << turns << " turns! The AI shot " << AI.getNMoves() << " times" << endl;
	}
	
}

void Game::InitGame(Player &p, AI &AI, Draw &drawManager) {
	int count = 1;
#pragma region AI_Ships
	while (AI.getNShips() < 11) {
		system("cls");
		cout << "AI is placing ships (" << count << "/11)" << endl;
		AI.putShip();
		count++;
		Sleep(250);
	}
#pragma endregion

#pragma region Player_Ships
	while (p.getNShips() < 11) {
		system("cls");
		cout << "Select the location of your ships!"; 
		drawManager.DrawBoard(8, 4, p.getBoard());
		p.putShip();
		system("cls");
		cout << "Select the location of your ships!";
		drawManager.DrawBoard(8, 4, p.getBoard());
	}
#pragma endregion
	
	gameState = "game";
}

void Game::setGameOver(bool g) {
	gameover = g;
}

bool Game::getGameOver() {
	return gameover;
}

std::ostream& operator<<(std::ostream& os, const Game gm) {
	os << gm.gameState << ";" << gm.gameover << ";" << gm.turns << ";";
	return os;
}
