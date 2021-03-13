#pragma once
class Draw {
public:
	static void DrawAll();

private:
	static void DrawFirstLineBoard(int x0, int dx, int dxcell);
	static void DrawDataLineBoard(int x0, int dx, int dxcell);
	static void DrawMiddleLineBoard(int x0, int dx, int dxcell);
	static void DrawLastLineBoard(int x0, int dx, int dxcell);
	static void DrawBoard(int x0, int dx, int dxcell, int dy, int y0);
	static void DrawBoards(int x0, int dx, int dxcell, int dy, int y0);
	static void DrawCoordLetter(int x0, int dx);
};