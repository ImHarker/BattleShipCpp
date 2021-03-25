#pragma once
#include <iostream>

class NavalCoordinate {
	private:
		char x;
		int y;

	public: 
		NavalCoordinate();
		NavalCoordinate(char xx, int yy);
		NavalCoordinate(int xx, int yy);
		~NavalCoordinate();

		char getX() const;
		int getIntX() const;
		bool setX(int yy);
		bool setX(char xx);
		
		int getY() const;
		bool setY(int yy);



		void ask2Set();
		void show();

		bool operator == (const NavalCoordinate p) const;
		bool operator != (const NavalCoordinate p) const;

};

