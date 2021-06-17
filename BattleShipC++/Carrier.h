#pragma once
#include "Ship.h"
class Carrier : public Ship {
	private:
		int specialPos;
	public:
		Carrier();
		int getSpecialPos();
		void setSpecialPos(int pos);
		virtual ~Carrier();
		virtual bool integrity();
};

