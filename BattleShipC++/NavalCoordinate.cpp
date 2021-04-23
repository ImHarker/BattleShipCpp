#include "NavalCoordinate.h"

NavalCoordinate::NavalCoordinate() {
	x = 'A';
	y = 1;
	c = '.';
}

NavalCoordinate::NavalCoordinate(char xx, int yy, char cc) {
	x = xx;
	y = yy;
	c = cc;
}

NavalCoordinate::NavalCoordinate(int xx, int yy, char cc) {
	x = (char)(xx + 64);
	y = yy;
	c = cc;
}

NavalCoordinate::~NavalCoordinate(){
}

char NavalCoordinate::getX() const {
	return x;
}

int NavalCoordinate::getIntX() const {
	return ((int)x - 64);
}

int NavalCoordinate::getY() const {
	return y;
}


bool NavalCoordinate::setY(int yy) {
	if (yy < 1 || yy > 10 ) {
		std::cout << "Invalid Y coordinate: " << yy << std::endl;
		return false;
	}
	y = yy;
	return true;
}

char NavalCoordinate::getC() const{
	return c;
}

bool NavalCoordinate::setC(char cc) {
	cc = toupper(cc);
	if (cc != '.' && cc != 'O' && cc != 'T' && cc != 'A') {
		std::cout << "Invalid Char: " << cc << std::endl;
		return false;
		}
	c = cc;
	return true;
	}

bool NavalCoordinate::setX(char xx) {
	if (xx < 'A' || xx > 'J') {
		std::cout << "Invalid X coordinate: " << xx << std::endl;
		return false;
	}
	x = xx;
	return true;
}

bool NavalCoordinate::setX(int xx) {
	if (xx < 1 || xx > 10) {
		std::cout << "Invalid X coordinate: " << (char)(xx+64) << std::endl;
		return false;
	}
	x = (char)(xx+64);
	return true;
}

void NavalCoordinate::ask2Set() {
	char xx;
	int yy;

	do {
		std::cout << "Insert a value to X: ";
		std::cin >> xx;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		xx = toupper(xx);
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

void NavalCoordinate::show() {
	std::cout << '(' << x << ',' << y << ',' << c << ')' << std::endl;
}

bool NavalCoordinate::operator == (const NavalCoordinate p) const {
	if (getX() == p.getX() && getY() == p.getY() && getC() == p.getC())
		return true;

	return false;
}

bool NavalCoordinate::operator != (const NavalCoordinate p) const {
	if (*this == p)
		return false;

	return true;
}

void NavalCoordinate::operator=(const NavalCoordinate p) {
	x = p.getX();
	y = p.getY();
	c = p.getC();
}

std::ostream& operator<<(std::ostream& os, const NavalCoordinate nc) {
	os << "(" << nc.getIntX() << "," << nc.getY() << "," << nc.getC() << ")" << ";";

	return os;
}
