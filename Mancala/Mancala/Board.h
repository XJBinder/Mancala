#pragma once
#include <iostream>
#include "Pit.h"

using std::cout;
using std::endl;

class Board
{
	// Attributes
	Pit pits[14];

public:
	// Constructor
	Board();

	// Methods
	void printBoard();
	int makeMove(int pitNumb, bool CPU);
	int checkPit(int pitNumb);
	bool gameOver();

	// Destructor
	~Board();
};