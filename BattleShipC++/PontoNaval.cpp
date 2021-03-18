#include "PontoNaval.h"

PontoNaval::PontoNaval() {
	x = 'A';
	y = 1;
}

PontoNaval::PontoNaval(char xx, int yy) {
	x = xx;
	y = yy;
}

PontoNaval::PontoNaval(int xx, int yy) {
	x = (char)(xx + 64);
	y = yy;
}

PontoNaval::~PontoNaval(){
}

char PontoNaval::getX() const {
	return x;
}

int PontoNaval::getIntX() const {
	return ((int)x - 64);
}

int PontoNaval::getY() const {
	return y;
}


bool PontoNaval::setY(int yy) {
	if (yy < 1 || yy > 10 ) {
		std::cout << "Invalid Y coordinate: " << yy << std::endl;
		return false;
	}
	y = yy;
	return true;
}

bool PontoNaval::setX(char xx) {
	if (xx < 'A' || xx > 'J') {
		std::cout << "Invalid X coordinate: " << xx << std::endl;
		return false;
	}
	x = xx;
	return true;
}

bool PontoNaval::setX(int xx) {
	if (xx < 1 || xx > 10) {
		std::cout << "Invalid X coordinate: " << (char)(xx+64) << std::endl;
		return false;
	}
	x = (char)(xx+64);
	return true;
}

void PontoNaval::ask2Set() {
	char xx;
	int yy;

	do {
		std::cout << "Insert a value to X: ";
		std::cin >> xx;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		xx = std::toupper(xx);
	} while (!setX(xx));

	do {
		std::cout << "Insert a value to Y: ";
		while (!(std::cin >> yy)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid number" << std::endl;
			std::cout << "Insert a value to Y: ";
		}
	} while (!setY(yy));
}

void PontoNaval::show() {
	std::cout << '(' << x << ',' << y << ')' << std::endl;
}

bool PontoNaval::operator == (const PontoNaval p) const {
	if (getX() == p.getX() && getY() == p.getY())
		return true;

	return false;
}

bool PontoNaval::operator != (const PontoNaval p) const {
	if (*this == p)
		return false;

	return true;
}
