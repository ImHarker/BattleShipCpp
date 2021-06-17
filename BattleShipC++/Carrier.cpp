#include "Carrier.h"

Carrier::Carrier() : Ship(3,1) {
	specialPos = 0;
}

int Carrier::getSpecialPos() {
	return specialPos;
}

void Carrier::setSpecialPos(int pos) {
	specialPos = pos;
}

Carrier::~Carrier() {
	specialPos = 0;
}

bool Carrier::integrity() {
	if (getHits() == getW() * getH() + 2) {
		sink();
		return true;
	}
	return false;
}
