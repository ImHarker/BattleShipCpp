#include "Draw.h"
#include "PontoNaval.h"

#include <iostream>


int main() {
	std::cout << "Welcome To BattleShip" << std::endl;
	Draw::DrawAll();
	PontoNaval p1;
	PontoNaval p2('A', 7);
	PontoNaval p3(1, 7);
	PontoNaval p4(1, 8);

	p1.show();
	p2.show();

	p1.setX('F');
	p1.setY(21);
	p1.setY(10);
	p1.show();

	p2.ask2Set();
	p2.show();

	p3.show();
	std::cout << p3.getIntX() << std::endl;
	if (p2 == p3) {
		std::cout << "p2 p3 iguais";
	} else {
		std::cout << "p2 p3 dif"; 
	}
	if (p2 != p4) {
		std::cout << "p2 p4 dif";
	} else {
		std::cout << "p2 p4 iguais";
	}

	return 0;
}