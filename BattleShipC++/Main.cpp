#include <iostream>

void DrawFirstLineBoard(int x0, int dx, int dxcell);
void DrawDataLineBoard(int x0, int dx, int dxcell);
void DrawMiddleLineBoard(int x0, int dx, int dxcell);
void DrawLastLineBoard(int x0, int dx, int dxcell);
void DrawBoard(int x0,int dx,int dxcell, int dy, int y0);
void DrawBoards(int x0, int dx, int dxcell, int dy, int y0);
void DrawCoordLetter(int x0, int dx);


int main() {
	std::cout << "Welcome To BattleShip" << std::endl;

	DrawBoards(12, 10, 3, 10, 4);

	return 0;
}

void DrawFirstLineBoard(int x0, int dx, int dxcell) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}

	std::cout << (char)218;
	for (i = 0; i < dx; i++) {
		for (j = 0; j < dxcell; j++) {
			std::cout << (char)196;
		}
		if(i<dx-1)
		std::cout << (char)194;
	}
	std::cout << (char)191;
}

void DrawDataLineBoard(int x0, int dx, int dxcell) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}

	for (i = 0; i < dx; i++) {
		std::cout << (char)179;
		std::cout << " "<< "." << " ";
	}
	std::cout << (char)179;
}

void DrawMiddleLineBoard(int x0, int dx, int dxcell) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}
	std::cout << (char)195;
	for (i = 0; i < dx; i++) {
		for (j = 0; j < dxcell; j++) {
			std::cout << (char)196;
		}
		if (i < dx - 1)
			std::cout << (char)197;
	}
	std::cout << (char)180;
}

void DrawLastLineBoard(int x0, int dx, int dxcell) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}
	std::cout << (char)192;
	for (i = 0; i < dx; i++) {
		for (j = 0; j < dxcell; j++) {
			std::cout << (char)196;
		}
		if (i < dx - 1)
			std::cout << (char)193;
	}
	std::cout << (char)217;
}

void DrawBoard(int x0, int dx, int dxcell, int dy, int y0) {
	int i, j;
	for (i = 0; i < y0; i++)
		std::cout << std::endl;
	DrawCoordLetter(x0, dx);
	std::cout << std::endl;
	DrawFirstLineBoard(x0, dx, dxcell);
	for (i = 0; i < dy; i++) {
		std::cout << std::endl;
		if (i + 1 >= 10) {
			for (j = 0; j < x0 - 3; j++)
				std::cout << " ";
		} else {
			for (j = 0; j < x0 - 2; j++)
				std::cout << " ";
		}
		std::cout << i+1 << " ";
		DrawDataLineBoard(0, dx, dxcell);
		if (i < dy - 1) {
			std::cout << std::endl;
			DrawMiddleLineBoard(x0, dx, dxcell);
		}
		}
	std::cout << std::endl;
	DrawLastLineBoard(x0, dx, dxcell);
	std::cout << std::endl;
}

void DrawBoards(int x0, int dx, int dxcell, int dy, int y0) {
	int i, j;
	for (i = 0; i < y0; i++)
		std::cout << std::endl;
	DrawCoordLetter(x0, dx);
	DrawCoordLetter(x0+1, dx);
	std::cout << std::endl;
	DrawFirstLineBoard(x0, dx, dxcell);
	DrawFirstLineBoard(x0, dx, dxcell);
	for (i = 0; i < dy; i++) {
		std::cout << std::endl;
		if (i + 1 >= 10) {
			for (j = 0; j < x0 - 3; j++)
				std::cout << " ";
		} else {
			for (j = 0; j < x0 - 2; j++)
				std::cout << " ";
		}
		std::cout << i + 1 << " ";
		DrawDataLineBoard(0, dx, dxcell);
		if (i + 1 >= 10) {
			for (j = 0; j < x0 - 3; j++)
				std::cout << " ";
		} else {
			for (j = 0; j < x0 - 2; j++)
				std::cout << " ";
		}
		std::cout << i + 1 << " ";
		DrawDataLineBoard(0, dx, dxcell);
		if (i < dy - 1) {
			std::cout << std::endl;
			DrawMiddleLineBoard(x0, dx, dxcell);
			DrawMiddleLineBoard(x0, dx, dxcell);
		}
	}
	std::cout << std::endl;
	DrawLastLineBoard(x0, dx, dxcell);
	DrawLastLineBoard(x0, dx, dxcell);
	std::cout << std::endl;
}

void DrawCoordLetter(int x0, int dx) {
	int i;
	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}

	for (i = 0; i < dx; i++) {
		std::cout << "  " << (char)(65 + i) << " ";
	}
}