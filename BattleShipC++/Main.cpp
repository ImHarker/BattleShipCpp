#include <iostream>

int main() {
	std::cout << "Welcome To BattleShip" << std::endl;
	int i, j;
	for (i = 0; i < 11; i++) {
		for (j = 0; j < 11; j++) {
			if (i == 0 && j == 0) {
			std::cout << "[ ]";
			} else if (i == 0) {
				std::cout << "[" << j-1 << "]";
			} else if (j == 0) {
				std::cout << "[" << (char)(64 + i) << "]";
			}else {
			std::cout << "[ ]";
		}
	}
		std::cout << std::endl;
	}

	return 0;
}