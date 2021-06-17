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
	virtual ~Ship();

	NavalCoordinate& getLocation();

	int getW();
	int getH();
	int getHits();
	void setSize(int width, int height);
	void hit();
	void sink();
	virtual bool integrity();

	friend std::ostream& operator<<(std::ostream& os, const Ship sh);
};

