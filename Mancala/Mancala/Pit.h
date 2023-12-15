#pragma once

class Pit
{
protected:
	// Attributes
	int marbles;

public:
	// Constructor
	Pit();
	Pit(int setMarbles);

	// Methods
	int showMarbles();
	void setMarbles(int setMarbles);

	// Destructor
	~Pit();
};