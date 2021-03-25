#pragma once
class Board {
private:
	int width;
	int height;
	char matrix[10][10];

public:
	Board();
	Board(int w, int h);
	~Board();

	void setWidth(int w);
	int getWidth();

	void setHeight(int h);
	int getHeight();

	void setMatrixCell(int row, int col, char c);
	char getMatrixCell(int row, int col);

};

