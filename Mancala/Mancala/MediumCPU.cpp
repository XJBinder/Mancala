#include "MediumCPU.h"

// Constructor
MediumCPU::MediumCPU(Board& board) : EasyCPU(board) {

}

// Method
int MediumCPU::CPUMove() {
    int cpuMove;

    // Check opportunity for extra move
    for (int i = 13; i > 7; --i) {
        if (currentMarbles[i] == 14 - i) {
            return i;
        }
    }

    // Else pick randomly
    cpuMove = 8 + (rand() % 6);
    while (currentMarbles[cpuMove] == 0) {
        cpuMove = 8 + (rand() % 6);
    }
    return cpuMove;
}

// Destructor
MediumCPU::~MediumCPU() {

}