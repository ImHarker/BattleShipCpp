#include "Ship.h"

Ship::Ship(){
	w = 0;
	h = 0;
	hits = 0;
	sunken = false;
}


Ship::Ship(int width, int height) {
	w = width;
	h = height;
	hits = 0;
	sunken = false;
}

Ship::~Ship(){
}

NavalCoordinate& Ship::getLocation() {
	return location;
}

void Ship::setSize(int width, int height) {
	w = width;
	h = height;
}

void Ship::hit(){
	hits++;
}

void Ship::sink() {
	sunken = true;
}

std::ostream& operator<<(std::ostream& os, const Ship sh) {
	os << sh.location << sh.w << ";" << sh.h << ";" << sh.hits << ";" << sh.sunken << ";";
	return os;
}
