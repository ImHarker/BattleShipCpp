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

void Board::setMatrixCell(int x, int y, char c) {
	matrix[y - 1][x - 1].setY(y);
	matrix[y - 1][x - 1].setX(x);
	matrix[y - 1][x - 1].setC(c);
}

void Board::setMatrixCell(NavalCoordinate nc) {
	matrix[nc.getY() - 1][nc.getIntX() - 1] = nc;
}

NavalCoordinate Board::getMatrixCell(int row, int col) {
	return matrix[row-1][col-1];
}

void Board::reset() {
	int i, j;
	NavalCoordinate nc;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			nc.setX(j+1);
			nc.setY(i+1);
			nc.setC('.');
			matrix[i][j] = nc;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Board b) {
	int i, j;
	os << b.width << ";" << b.height << ";";
	os << std::endl;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			os << b.matrix[i][j];
		}
		os << std::endl;
	}
	
	return os;

}
