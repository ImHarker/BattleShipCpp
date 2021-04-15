#include <iostream>
#include "Board.h"

Board::Board() {
	int i, j;
	setWidth(10);
	setHeight(10);

	for (i = 1; i <= getWidth(); i++)
		for (j = 1; j <= getHeight(); j++)
			setMatrixCell(i, j, '.');
}

Board::Board(int w, int h) {
	int i, j;
	setWidth(w);
	setHeight(h);

	for (i = 1; i <= getWidth(); i++)
		for (j = 1; j <= getHeight(); j++)
			setMatrixCell(i, j, '.');
}

Board::~Board() {
}

void Board::setWidth(int w) {
	width = w;
}

int Board::getWidth() {
	return width;
}

void Board::setHeight(int h) {
	height = h;
}

int Board::getHeight() {
	return height;
}

void Board::setMatrixCell(int row, int col, char c) {
	matrix[row - 1][col - 1].setY(row);
	matrix[row - 1][col - 1].setX(col);
	matrix[row - 1][col - 1].setC(c);
}

void Board::setMatrixCell(NavalCoordinate nc) {
	matrix[nc.getIntX() - 1][nc.getY() - 1] = nc;
}

NavalCoordinate Board::getMatrixCell(int row, int col) {
	return matrix[row-1][col-1];
}

