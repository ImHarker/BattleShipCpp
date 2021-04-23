#pragma once
#include "NavalCoordinate.h"
class Ship{
private:
	NavalCoordinate location;
	int w, h;
	int hits;
	bool sunken;
public:
	Ship();
	Ship(int width, int height);
	~Ship();

	NavalCoordinate& getLocation();

	void setSize(int width, int height);
	void hit();
	void sink();

	friend std::ostream& operator<<(std::ostream& os, const Ship sh);
};

