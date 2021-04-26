#include "AI.h"


AI::AI() : Player(){
	setName("AI");
}

AI::~AI() {
}

void AI::putShip() {
	Submarine *sub = new Submarine;
	int x, y;

	//generates random positions and checks adjacent ships
	do{
	x = rand() % 10 + 1;
	y = rand() % 10 + 1;
	}while (isAdjacent(x,y));

		sub->getLocation().setX(x);
		sub->getLocation().setY(y);
		sub->getLocation().setC('O');
		getBoard().setMatrixCell(sub->getLocation());
		setShips(sub);
		setNShips(getNShips() + 1);
	
}

void AI::play(Player &enemy, Draw drawManager) {
	int x, y;
	system("cls");
	cout << "AI Turn" << endl;

	if (getNMoves() == 99) {
		setAmmo(1);
	} else {
		setAmmo(3);
	}

	while (getAmmo() > 0 && getNShips() > 0) {
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;

		system("cls");
		cout << "Your Board";
		drawManager.DrawBoard(8, 2, getBoardView());
		cout << endl << "AI is attemping to shoot at (" << (char)(x + 64) << "," << y << ")!" << endl;
		Sleep(2500);

		playMove(x, y, enemy, drawManager);

	}
	
}
