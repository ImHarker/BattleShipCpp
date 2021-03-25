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
	matrix[row-1][col-1] = c;
}

char Board::getMatrixCell(int row, int col) {
	return matrix[row-1][col-1];
}

void Board::DrawDataLine(int x0, int line) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}

	for (i = 0; i < getWidth(); i++) {
		std::cout << (char)179;
		std::cout << " " << getMatrixCell(line+1,i+1) << " ";
	}
	std::cout << (char)179;
}
void Board::DrawFirstLine(int x0) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}
	std::cout << (char)218;
	for (i = 0; i < getWidth(); i++) {
		for (j = 0; j < 3; j++) {
			std::cout << (char)196;
		}
		if (i < getWidth() - 1)
			std::cout << (char)194;
	}
	std::cout << (char)191;
}


void Board::DrawMiddleLine(int x0) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}
	std::cout << (char)195;
	for (i = 0; i < getWidth(); i++) {
		for (j = 0; j < 3; j++) {
			std::cout << (char)196;
		}
		if (i < getWidth() - 1)
			std::cout << (char)197;
	}
	std::cout << (char)180;
}

void Board::DrawLastLine(int x0) {
	int i, j;

	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}
	std::cout << (char)192;
	for (i = 0; i < getWidth(); i++) {
		for (j = 0; j < 3; j++) {
			std::cout << (char)196;
		}
		if (i < getWidth() - 1)
			std::cout << (char)193;
	}
	std::cout << (char)217;
}

void Board::Draw(int x0, int y0) {
	int i, j;
	x0 += 3;
	for (i = 0; i < y0; i++)
		std::cout << std::endl;
	DrawCoordLetter(x0);
	std::cout << std::endl;
	DrawFirstLine(x0);
	for (i = 0; i < getHeight(); i++) {
		std::cout << std::endl;
		if (i + 1 >= 10) {
			for (j = 0; j < x0 - 3; j++)
				std::cout << " ";
		} else {
			for (j = 0; j < x0 - 2; j++)
				std::cout << " ";
		}
		std::cout << i + 1 << " ";
		DrawDataLine(0, i);
		if (i < getHeight() - 1) {
			std::cout << std::endl;
			DrawMiddleLine(x0);
		}
	}
	std::cout << std::endl;
	DrawLastLine(x0);
	std::cout << std::endl;
}


void Board::DrawCoordLetter(int x0) {
	int i;
	for (i = 0; i < x0; i++) {
		std::cout << " ";
	}

	for (i = 0; i < getWidth(); i++) {
		std::cout << "  " << (char)(65 + i) << " ";
	}
}
