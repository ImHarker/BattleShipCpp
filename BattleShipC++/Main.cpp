#include "Board.h"
#include "NavalCoordinate.h"

#include <iostream>


int main() {
	Board b;
	std::cout << "Welcome To BattleShip" << std::endl;
	b.setMatrixCell(2, 2, 'O');
	b.setMatrixCell(10, 10, 'O');
	b.Draw(8, 4);

	return 0;
}