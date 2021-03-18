#pragma once
#include <iostream>

class PontoNaval {
	private:
		char x;
		int y;

	public: 
		PontoNaval();
		PontoNaval(char xx, int yy);
		PontoNaval(int xx, int yy);

		char getX() const;
		int getIntX() const;
		bool setX(int yy);
		bool setX(char xx);
		
		int getY() const;
		bool setY(int yy);



		void ask2Set();
		void show();

		bool operator == (const PontoNaval p) const;
		bool operator != (const PontoNaval p) const;

		~PontoNaval();
};

