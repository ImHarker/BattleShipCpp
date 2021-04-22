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
	string battle = R"(  ___     _     _____   _____   _      ___        ___   _  _   ___   ___         ___     _     __  __   ___ 
 | _ )   /_\   |_   _| |_   _| | |    | __|      / __| | || | |_ _| | _ \       / __|   /_\   |  \/  | | __|
 | _ \  //_\\    | |     | |   | |__  | _|       \__ \ | __ |  | |  |  _/      | (_\   //_\\  | |\/| | | _| 
 |___/ /_/ \_\   |_|     |_|   |____| |___|      |___/ |_||_| |___| |_|         \___| /_/ \_\ |_|  |_| |___|)";
	string newgame = R"(	  _  _   ___  __      __        ___     _     __  __   ___ 
	 | \| | | __| \ \    / /       / __|   /_\   |  \/  | | __|
	 | .` | | _|   \ \/\/ /       | (_\   //_\\  | |\/| | | _| 
	 |_|\_| |___|   \_/\_/         \___| /_/ \_\ |_|  |_| |___|)";
	string newgame_s = R"(    __    _  _   ___  __      __        ___     _     __  __   ___ 
  __\ \  | \| | | __| \ \    / /       / __|   /_\   |  \/  | | __|
 |___> > | .` | | _|   \ \/\/ /       | (_\   //_\\  | |\/| | | _| 
    /_/  |_|\_| |___|   \_/\_/         \___| /_/ \_\ |_|  |_| |___|)";
	string load = R"(	  _       ___      _     ___          ___     _     __  __   ___ 
	 | |     / _ \    /_\   |   \        / __|   /_\   |  \/  | | __|
	 | |__  | (_) |  //_\\  | |) |      | (_\   //_\\  | |\/| | | _| 
	 |____|  \___/  /_/ \_\ |___/        \___| /_/ \_\ |_|  |_| |___|)";
	string load_s = R"(    __    _       ___      _     ___          ___     _     __  __   ___ 
  __\ \  | |     / _ \    /_\   |   \        / __|   /_\   |  \/  | | __|
 |___> > | |__  | (_) |  //_\\  | |) |      | (_\   //_\\  | |\/| | | _| 
    /_/  |____|  \___/  /_/ \_\ |___/        \___| /_/ \_\ |_|  |_| |___|)";
	string rules = R"(	  ___   _   _   _      ___   ___ 
	 | _ \ | | | | | |    | __| / __|
	 |   / | |_| | | |__  | _|  \__ \
	 |_|_\  \___/  |____| |___| |___/)";
	string rules_s = R"(    __    ___   _   _   _      ___   ___ 
  __\ \  | _ \ | | | | | |    | __| / __|
 |___> > |   / | |_| | | |__  | _|  \__ \
    /_/  |_|_\  \___/  |____| |___| |___/)";
	string credits = R"(	   ___   ___   ___   ___    ___   _____   ___ 
	  / __| | _ \ | __| |   \  |_ _| |_   _| / __|
	 | (__  |   / | _|  | |) |  | |    | |   \__ \
	  \___| |_|_\ |___| |___/  |___|   |_|   |___/)";
	string credits_s = R"(    __     ___   ___   ___   ___    ___   _____   ___ 
  __\ \   / __| | _ \ | __| |   \  |_ _| |_   _| / __|
 |___> > | (__  |   / | _|  | |) |  | |    | |   \__ \
    /_/   \___| |_|_\ |___| |___/  |___|   |_|   |___/)";

	bool inmenu = true;
	int menu = 500000;
	int _menu = 1;
	std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << newgame_s << std::endl;
	std::cout << load << std::endl;
	std::cout << rules << std::endl;
	std::cout << credits << std::endl;

	while (inmenu) {
		switch (_getch()) {
		case 72:
			menu--;//key up
			break;
		case 80:
			menu++;  // key down
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
				std::cout << (char)184 << " Gustavo Santos al70800" << std::endl;
				std::cout << "  Vasco Teixeira al74107" << std::endl;
				std::cout << "  Universidade de Tras-os-Montes e Alto Douro" << std::endl;
				inmenu = false;
				break;
			}
			break;
		}
		if (menu != _menu && inmenu) {
			switch (abs(menu % 4)) {
			case 0:
				system("cls");
				std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				std::cout << newgame_s << std::endl;
				std::cout << load << std::endl;
				std::cout << rules << std::endl;
				std::cout << credits << std::endl;
				break;
			case 1:
				system("cls");
				std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				std::cout << newgame << std::endl;
				std::cout << load_s << std::endl;
				std::cout << rules << std::endl;
				std::cout << credits << std::endl;
				break;
			case 2:
				system("cls");
				std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				std::cout << newgame << std::endl;
				std::cout << load << std::endl;
				std::cout << rules_s << std::endl;
				std::cout << credits << std::endl;
				break;
			case 3:
				system("cls");
				std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				std::cout << newgame << std::endl;
				std::cout << load << std::endl;
				std::cout << rules << std::endl;
				std::cout << credits_s << std::endl;
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