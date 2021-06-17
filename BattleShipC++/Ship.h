#pragma once
#include "NavalCoordinate.h"
class Ship{
private:
	NavalCoordinate location;
	int w, h;
	int hits;
	bool sunken;
	char heading;
public:
	Ship();
	Ship(int width, int height);
	virtual ~Ship();

	NavalCoordinate& getLocation();

	void setHeading(char head);
	char getHeading();
	int getW();
	int getH();
	void setSize(int width, int height);
	void hit();
	virtual bool integrity();

	friend std::ostream& operator<<(std::ostream& os, const Ship sh);
};

