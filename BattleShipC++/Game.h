#pragma once
#include <string>
#include "Player.h"
#include "AI.h"
#include "Board.h"
#include "Draw.h"
class Game {
private:
	std::string gameState;
public:
	void GameLoop();
};
