#include "Draw.h"
#include "Game.h"
#include <conio.h>
#include <iostream>

Draw::Draw(Board &player, Board &playerEnemy, Board &AI, Board &AIPlayer) {
	boardsPlayer[0] = &player;
	boardsPlayer[1] = &playerEnemy;
	boardsAI[0] = &AI;
	boardsAI[1] = &AIPlayer;
}

void Draw::DrawPlayer() {
	DrawBoards(*boardsPlayer[0], *boardsPlayer[1], 8, 4);
}
void Draw::DrawAI() {
	DrawBoards(*boardsAI[0], *boardsAI[1], 8, 4);
}

void Draw::Menu() {
	Game game;

	bool inmenu = true;
	int menu = 0;
	int _menu = 1;
	std::cout << "Welcome To BattleShip" << std::endl << std::endl << std::endl;
	std::cout << "-> Jogar" << std::endl;
	std::cout << "   Salvar" << std::endl;
	std::cout << "   Regras" << std::endl;
	std::cout << "   Creditos" << std::endl;

	while (inmenu) {
		switch (_getch()) {
		case 72:
			menu++;//key up
			break;
		case 80:
			menu--;  // key down
			break;
		case 13:
			switch (abs(menu % 4)) {
			case 0:
				system("cls");
				inmenu = false;
				game.GameLoop();
				break;
			case 1:
				system("cls");
				std::cout << "SALVAR!";
				inmenu = false;
				break;
			case 2:
				system("cls");
				std::cout << "REGRAS!";
				inmenu = false;
				break;
			case 3:
				system("cls");
				std::cout << "CREDITOS!";
				inmenu = false;
				break;
			}
			break;
		}
		if (menu != _menu && inmenu) {
			switch (abs(menu % 4)) {
			case 0:
				system("cls");
				std::cout << "Welcome To BattleShip" << std::endl << std::endl << std::endl;
				std::cout << "-> Jogar" << std::endl;
				std::cout << "   Salvar" << std::endl;
				std::cout << "   Regras" << std::endl;
				std::cout << "   Creditos" << std::endl;
				break;
			case 1:
				system("cls");
				std::cout << "Welcome To BattleShip" << std::endl << std::endl << std::endl;
				std::cout << "   Jogar" << std::endl;
				std::cout << "-> Salvar" << std::endl;
				std::cout << "   Regras" << std::endl;
				std::cout << "   Creditos" << std::endl;
				break;
			case 2:
				system("cls");
				std::cout << "Welcome To BattleShip" << std::endl << std::endl << std::endl;
				std::cout << "   Jogar" << std::endl;
				std::cout << "   Salvar" << std::endl;
				std::cout << "-> Regras" << std::endl;
				std::cout << "   Creditos" << std::endl;
				break;
			case 3:
				system("cls");
				std::cout << "Welcome To BattleShip" << std::endl << std::endl << std::endl;
				std::cout << "   Jogar" << std::endl;
				std::cout << "   Salvar" << std::endl;
				std::cout << "   Regras" << std::endl;
				std::cout << "-> Creditos" << std::endl;
				break;

			}
			_menu = menu;
		}
	}

}

#pragma region Board Construction
void Draw::DrawDataLineBoard(int x0, int line, Board board) {
	int i;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}

	for (i = 0; i < board.getWidth(); i++) {
		std::cout << (char)179;
		std::cout << " " << board.getMatrixCell(line + 1, i + 1).getC() << " ";
	}
	std::cout << (char)179;
}
void Draw::DrawFirstLineBoard(int x0, Board board) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}
	std::cout << (char)218;
	for (i = 0; i < board.getWidth(); i++) {
		for (j = 0; j < 3; j++) {
			std::cout << (char)196;
		}
		if (i < board.getWidth() - 1)
			std::cout << (char)194;
	}
	std::cout << (char)191;
}


void Draw::DrawMiddleLineBoard(int x0, Board board) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}
	std::cout << (char)195;
	for (i = 0; i < board.getWidth(); i++) {
		for (j = 0; j < 3; j++) {
			std::cout << (char)196;
		}
		if (i < board.getWidth() - 1)
			std::cout << (char)197;
	}
	std::cout << (char)180;
}

void Draw::DrawLastLineBoard(int x0, Board board) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}
	std::cout << (char)192;
	for (i = 0; i < board.getWidth(); i++) {
		for (j = 0; j < 3; j++) {
			std::cout << (char)196;
		}
		if (i < board.getWidth() - 1)
			std::cout << (char)193;
	}
	std::cout << (char)217;
}

void Draw::DrawCoordLetter(int x0, Board board) {
	int i;
	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}

	for (i = 0; i < board.getWidth(); i++) {
		std::cout << "  " << (char)(65 + i) << " ";
	}
}
#pragma endregion

void Draw::DrawBoard(int x0, int y0, Board board) {
	int i, j;
	x0 += 3;
	for (i = 0; i < y0; i++)
		std::cout << std::endl;
	DrawCoordLetter(x0, board);
	std::cout << std::endl;
	DrawFirstLineBoard(x0, board);
	for (i = 0; i < board.getHeight(); i++) {
		std::cout << std::endl;
		if (i + 1 >= 10) {
			for (j = 0; j < x0 - 3; j++)
				std::cout << " ";
		} else {
			for (j = 0; j < x0 - 2; j++)
				std::cout << " ";
		}
		std::cout << i + 1 << " ";
		DrawDataLineBoard(0, i, board);
		if (i < board.getHeight() - 1) {
			std::cout << std::endl;
			DrawMiddleLineBoard(x0, board);
		}
	}
	std::cout << std::endl;
	DrawLastLineBoard(x0, board);
	std::cout << std::endl;
}

void Draw::DrawBoards(Board board, Board board2, int x0, int y0) {
	int i, j;
	for (i = 0; i < y0; i++)
		std::cout << std::endl;
	DrawCoordLetter(x0, board);
	DrawCoordLetter(x0 + 1, board2);
	std::cout << std::endl;
	DrawFirstLineBoard(x0, board);
	DrawFirstLineBoard(x0, board2);
	for (i = 0; i < board.getHeight(); i++) {
		std::cout << std::endl;
		if (i + 1 >= 10) {
			for (j = 0; j < x0 - 3; j++)
				std::cout << " ";
		} else {
			for (j = 0; j < x0 - 2; j++)
				std::cout << " ";
		}
		std::cout << i + 1 << " ";
		DrawDataLineBoard(0, i, board);
		if (i + 1 >= 10) {
			for (j = 0; j < x0 - 3; j++)
				std::cout << " ";
		} else {
			for (j = 0; j < x0 - 2; j++)
				std::cout << " ";
		}
		std::cout << i + 1 << " ";
		DrawDataLineBoard(0, i, board2);
		if (i < board.getHeight() - 1) {
			std::cout << std::endl;
			DrawMiddleLineBoard(x0, board);
			DrawMiddleLineBoard(x0, board2);
		}
	}
	std::cout << std::endl;
	DrawLastLineBoard(x0, board);
	DrawLastLineBoard(x0, board2);
	std::cout << std::endl;
}