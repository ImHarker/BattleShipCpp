#include "Draw.h"
#include "Game.h"
#include "Player.h"
#include <conio.h>
#include <iostream>

Draw::Draw(Board &player, Board &playerEnemy, Board &AI, Board &AIPlayer) {
	boardsPlayer[0] = &player;
	boardsPlayer[1] = &playerEnemy;
	boardsAI[0] = &AI;
	boardsAI[1] = &AIPlayer;
}

void Draw::DrawPlayer() {
	DrawBoards(*boardsPlayer[0], *boardsPlayer[1], 8, 2);
}
void Draw::DrawAI() {
	DrawBoards(*boardsAI[0], *boardsAI[1], 8, 2);
}

void Draw::Menu() {
	Game game;
	Player ex;
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
	string exit = R"(	  ___  __  __  ___   _____ 
	 | __| \ \/ / |_ _| |_   _|
	 | _|   >  <   | |    | |  
	 |___| /_/\_\ |___|   |_|  )";
	string exit_s = R"(    __    ___  __  __  ___   _____ 
  __\ \  | __| \ \/ / |_ _| |_   _|
 |___> > | _|   >  <   | |    | |  
    /_/  |___| /_/\_\ |___|   |_|)";
	string rules_txt = R"(The gameplay is straightforward. Each player hides ships on a grid containing vertical and horizontal space coordinates. 
Players take turns calling out column(X) and row(Y) coordinates on the other player's grid in an attempt to identify a 
square that contains a ship. 

The game has two grids: right and left grid. 
The left grid is used by the player to "hide" the location of his own ships, while the right grid is used to record the shots fired toward the opponent and to document whether those shots were hits or misses.

How to Play the Game

		Each player has 11 ships of varying lengths:

			+-----+------------+---------+------+
			|COUNT|    NAME    |  SHAPE  |  HP  | 
			|  4  | Submarine  | 1 by 1  |   1  |
			|  3  | Destroyer  | 2 by 1  |   2  |
			|  2  | Cruiser    | 3 by 1  |   3  |
			|  1  | Battleship | 4 by 1  |   4  |
			|  1  | Carrier    | T shape |   5  |
			+-----+------------+---------+------+
	
		Each player will place the 11 ships in the board and must follow these rules:
			The ships can only be place in the vertical or horizontal axis
			Ships can't be adjacent to each other
	
		Each ship has a Health value, the HP is the number of spots that the ship occupy in the board.
 
		Each player will take 3 shots per turn, bellow you can see the key that we will use to represent shots 
		and ships.
		
	Destroying Ships
		
		To destroy a ship the player will need to hit every spot that the ship occupies in the board.
		
	
	The Board
	
		The board is a 10x10 grid with X(columns) and Y(rows) coordinates
		
		We gonna use the following key to represent shots hit, ships, shots missed and free places:

				'.' - Represents an empty space
				'O' - Represents a ship
				'T' - Represents a ship that was hit
				'A' - Represents a missed shot
)";
		string rules_boards = R"(	Board Examples:

	Empty Board:
		         A   B   C   D   E   F   G   H   I   J
		       +---+---+---+---+---+---+---+---+---+---+
		     1 | . | . | . | . | . | . | . | . | . | . |
		       +---+---+---+---+---+---+---+---+---+---+
		     2 | . | . | . | . | . | . | . | . | . | . |
		       +---+---+---+---+---+---+---+---+---+---+
		     3 | . | . | . | . | . | . | . | . | . | . |
		       +---+---+---+---+---+---+---+---+---+---+
		     4 | . | . | . | . | . | . | . | . | . | . |
		       +---+---+---+---+---+---+---+---+---+---+
		     5 | . | . | . | . | . | . | . | . | . | . |
		       +---+---+---+---+---+---+---+---+---+---+
		     6 | . | . | . | . | . | . | . | . | . | . |
		       +---+---+---+---+---+---+---+---+---+---+
		     7 | . | . | . | . | . | . | . | . | . | . |
		       +---+---+---+---+---+---+---+---+---+---+
		     8 | . | . | . | . | . | . | . | . | . | . |
		       +---+---+---+---+---+---+---+---+---+---+
		     9 | . | . | . | . | . | . | . | . | . | . |
		       +---+---+---+---+---+---+---+---+---+---+
		    10 | . | . | . | . | . | . | . | . | . | . |
		       +---+---+---+---+---+---+---+---+---+---+

	Player Boards:
		Board A:                                           Board B:
		
	          A   B   C   D   E   F   G   H   I   J            A   B   C   D   E   F   G   H   I   J
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	      1 | O | . | O | . | . | . | . | . | . | . |      1 | . | . | . | . | . | . | . | . | . | . |
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	      2 | . | . | . | . | . | . | . | . | . | . |      2 | . | T | . | . | . | . | . | . | . | . |
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	      3 | O | . | O | . | . | A | . | . | . | . |      3 | . | . | . | . | . | . | . | . | . | . |
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	      4 | . | . | . | . | . | . | . | . | . | . |      4 | . | . | . | . | A | . | . | . | . | . |
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	      5 | O | . | T | . | . | . | O | . | . | . |      5 | . | . | . | . | . | . | . | . | . | . |
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	      6 | . | . | . | . | . | . | . | . | . | . |      6 | . | . | . | . | . | A | . | . | . | . |
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	      7 | O | . | O | . | . | . | . | . | . | . |      7 | . | . | . | . | . | . | . | . | . | . |
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	      8 | . | . | . | . | . | . | A | . | . | . |      8 | . | . | . | . | . | . | . | . | . | . |
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	      9 | O | . | O | . | . | . | . | . | . | . |      9 | . | . | . | . | . | T | . | . | . | . |
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	     10 | . | . | . | . | . | . | . | . | . | . |     10 | . | . | . | . | . | . | . | . | . | . |
	        +---+---+---+---+---+---+---+---+---+---+        +---+---+---+---+---+---+---+---+---+---+
	
		Board A represents the player board! Board B represents the board with the shots taken of the player!
		In Board A will be displayed your ships and the shots taken by the other player.
		In Board B will only be displayed the places where u shot.

	AI Boards:
        Board C:
		
             A   B   C   D   E   F   G   H   I   J
           +---+---+---+---+---+---+---+---+---+---+
         1 | . | . | . | . | . | . | . | . | . | . |
           +---+---+---+---+---+---+---+---+---+---+
         2 | . | . | . | . | . | . | . | . | . | . |
           +---+---+---+---+---+---+---+---+---+---+
         3 | . | . | . | . | . | A | . | . | . | . |
           +---+---+---+---+---+---+---+---+---+---+
         4 | . | . | . | . | . | . | . | . | . | . |
           +---+---+---+---+---+---+---+---+---+---+
         5 | . | . | T | . | . | . | . | . | . | . |
           +---+---+---+---+---+---+---+---+---+---+
         6 | . | . | . | . | . | . | . | . | . | . |
           +---+---+---+---+---+---+---+---+---+---+
         7 | . | . | . | . | . | . | . | . | . | . |
           +---+---+---+---+---+---+---+---+---+---+
         8 | . | . | . | . | . | . | A | . | . | . |
           +---+---+---+---+---+---+---+---+---+---+
         9 | . | . | . | . | . | . | . | . | . | . |
           +---+---+---+---+---+---+---+---+---+---+
        10 | . | . | . | . | . | . | . | . | . | . |
           +---+---+---+---+---+---+---+---+---+---+

		The Board C will be displayed when AI is shooting. 
		It will display your board with the places where AI shot.)";

	bool inmenu = true;
	int menu = 500000;
	int _menu = 1;
	std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << newgame_s << std::endl;
	std::cout << load << std::endl;
	std::cout << rules << std::endl;
	std::cout << credits << std::endl;
	std::cout << exit << std::endl;

	while (inmenu) {
		switch (_getch()) {
		case 72:
			menu--;//key up
			break;
		case 80:
			menu++;  // key down
			break;
		case 13:
			switch (menu % 5) {
			case 0:
				system("cls");
				inmenu = false;
				game.GameLoop();
				break;
			case 1:
				system("cls");
				std::cout << "Load!";
				inmenu = false;
				break;
			case 2:
				system("cls");
				std::cout << rules_txt;
				system("pause");
				system("cls");
				std::cout << rules_boards << std::endl;
				system("pause");
				menu = 500000;
				break;
			case 3:
				system("cls");
				std::cout << (char)184 << " Gustavo Santos al70800" << std::endl;
				std::cout << "  Vasco Teixeira al74107" << std::endl;
				std::cout << "  Universidade de Tras-os-Montes e Alto Douro" << std::endl;
				system("start https://github.com/ImHarker/BattleShipCpp");
				inmenu = false;
				break;
			case 4:
				return;
			}
			break;
		}
		if (menu != _menu && inmenu) {
			switch (menu % 5) {
			case 0:
				system("cls");
				std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl;
				std::cout << newgame_s << std::endl;
				std::cout << load << std::endl;
				std::cout << rules << std::endl;
				std::cout << credits << std::endl;
				std::cout << exit << std::endl;
				break;
			case 1:
				system("cls");
				std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl;
				std::cout << newgame << std::endl;
				std::cout << load_s << std::endl;
				std::cout << rules << std::endl;
				std::cout << credits << std::endl;
				std::cout << exit << std::endl;
				break;
			case 2:
				system("cls");
				std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl;
				std::cout << newgame << std::endl;
				std::cout << load << std::endl;
				std::cout << rules_s << std::endl;
				std::cout << credits << std::endl;
				std::cout << exit << std::endl;
				break;
			case 3:
				system("cls");
				std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl;
				std::cout << newgame << std::endl;
				std::cout << load << std::endl;
				std::cout << rules << std::endl;
				std::cout << credits_s << std::endl;
				std::cout << exit << std::endl;
				break;
			case 4:
				system("cls");
				std::cout << battle << std::endl << std::endl << std::endl << std::endl << std::endl;
				std::cout << newgame << std::endl;
				std::cout << load << std::endl;
				std::cout << rules << std::endl;
				std::cout << credits << std::endl;
				std::cout << exit_s << std::endl;
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