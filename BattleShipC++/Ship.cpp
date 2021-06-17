#include "Ship.h"

Ship::Ship(){
	w = 0;
	h = 0;
	hits = 0;
	sunken = false;
	heading = 'h';
}


Ship::Ship(int width, int height) {
	w = width;
	h = height;
	hits = 0;
	sunken = false;
	heading = 'h';
}

Ship::~Ship(){
}

NavalCoordinate& Ship::getLocation() {
	return location;
}

void Ship::setHeading(char head) {
	heading = head;
}

char Ship::getHeading() {
	return heading;
}

int Ship::getW() {
	return w;
}

int Ship::getH() {
	return h;
}

void Ship::setSize(int width, int height) {
	w = width;
	h = height;
}

void Ship::hit(){
	hits++;
}

bool Ship::integrity() {
	if (hits == w * h) {
		sunken = true;
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Ship sh) {
	os << sh.location << sh.w << ";" << sh.h << ";" << sh.hits << ";" << sh.sunken << ";";
	return os;
}
