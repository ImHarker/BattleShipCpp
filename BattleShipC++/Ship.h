#pragma once
class Ship{
private:
	int w, h;
	int hits;
	bool sunken;
public:
	Ship();
	Ship(int width, int height);
	~Ship();
	void setSize(int width, int height);
	void hit();
	void sink();
};

