#pragma once
#include <iostream>

class NavalCoordinate {
	private:
		char x;
		int y;
		char c;

	public: 
		NavalCoordinate();
		NavalCoordinate(char xx, int yy, char cc);
		NavalCoordinate(int xx, int yy, char cc);
		~NavalCoordinate();

		char getX() const;
		int getIntX() const;
		bool setX(int xx);
		bool setX(char xx);
		
		int getY() const;
		bool setY(int yy);

		char getC() const;
		bool setC(char cc);


		void ask2Set();
		void show();

		bool operator == (const NavalCoordinate p) const;
		bool operator != (const NavalCoordinate p) const;

};

