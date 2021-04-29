#pragma once
#include "Player.h"
#include "Submarine.h"
#include <iostream>
#include <math.h>
class AI : public Player {
public:
	AI();
	virtual ~AI();
	virtual void putShip();

	virtual void play(Player &enemy, Draw drawManager, int turns);
};

