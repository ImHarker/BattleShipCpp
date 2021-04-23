#pragma once
#include <string>
#include "Player.h"
#include "AI.h"
#include "Board.h"
#include "Draw.h"
class Game {
private:
	std::string gameState;
	bool gameover;
	int turns;
public:
	void GameLoop();
	void InitGame(Player &p, AI &AI, Draw &drawManager);

	void setGameOver(bool g);
	bool getGameOver();
	
	friend std::ostream& operator<<(std::ostream& os, const Game gm);
};
