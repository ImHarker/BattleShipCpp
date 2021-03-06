#pragma once
#include <string>
#include <Windows.h>
#include "Board.h"
#include "Ship.h"
#include "Draw.h"
#include "Submarine.h"
using namespace std;

class Player {
private:
	string name;
	NavalCoordinate moves[100];
	Board board, boardView; //player board, and what player view from enemy board (Shots taken, Ship hits, etc)
	Ship *ships[11];
	int nMoves;
	int playerN;
	int ammo;
	int nShips;
public:
	Player();
	virtual ~Player();

	virtual void putShip();


	void setName(string n);
	void setBoard(Board b);
	void setBoardView(Board bv);
	void setPlayerN(int n);
	void setAmmo(int n);
	void setNShips(int n);
	void setShips(Ship* sh);
	void setNMoves(int n);
	void setMoves(NavalCoordinate move);

	string getName();
	int getPlayerN();
	int getAmmo();
	Board &getBoard();
	Board& getBoardView();
	int getNShips();
	Ship *getShip(int n);
	bool isAdjacent(Ship *ship);
	int getNMoves();
	NavalCoordinate getMove(int n);

	virtual void play(Player &enemy, Draw drawManager, int turns);
	void playMove(int x, int y, Player& enemy, Draw drawManager, int turns);

	friend std::ostream& operator<<(std::ostream& os, Player &p);

};

