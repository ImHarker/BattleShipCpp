#pragma once
#include "NavalCoordinate.h"
class Board {
private:
	int width;
	int height;
	NavalCoordinate matrix[10][10];

public:
	Board();
	Board(int w, int h);
	~Board();

	void setWidth(int w);
	int getWidth();

	void setHeight(int h);
	int getHeight();

	void setMatrixCell(int row, int col, char cc);
	void setMatrixCell(NavalCoordinate nc);
	NavalCoordinate getMatrixCell(int row, int col);

};

