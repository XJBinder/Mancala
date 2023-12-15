#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using std::cout;
using std::endl;

class EasyCPU
{
protected:
	// Attribute
	int currentMarbles[14];

public:
	// Constructor
	EasyCPU(Board& board);

	// Methods
	void readMarbles(Board& board);
	virtual int CPUMove();

	// Destructor
	~EasyCPU();
};