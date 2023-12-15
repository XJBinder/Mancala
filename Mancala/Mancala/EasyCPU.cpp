#include "EasyCPU.h"

// Constructor
EasyCPU::EasyCPU(Board& board) {
	srand(time(0));

	for (int i = 0; i < 14; i++) {
		currentMarbles[i] = board.checkPit(i);
	}
}

// Methods
void EasyCPU::readMarbles(Board& board) {
	for (int i = 0; i < 14; i++) {
		currentMarbles[i] = board.checkPit(i);
	}
}

int EasyCPU::CPUMove() {
	int cpuMove;

	// Check for empty pocket
	cpuMove = 8 + (rand() % 6);
	while (currentMarbles[cpuMove] == 0) {
		cpuMove = 8 + (rand() % 6);
	}
	return cpuMove;
}

// Destructor
EasyCPU::~EasyCPU() {

}