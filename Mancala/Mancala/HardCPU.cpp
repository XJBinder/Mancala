#include "HardCPU.h"

// Constructor
HardCPU::HardCPU(Board& board) : EasyCPU(board) {

}

// Method
int HardCPU::CPUMove() {
    int cpuMove, simulatedPit, simulatedEnd;

    // Check to capture Pit
    for (int i = 13; i > 7; i--) {
        if (currentMarbles[i] == 0) {
            continue;
        }
        // SimulatedPit = what Pit last Marble will land on
        simulatedPit = (i + currentMarbles[i]) % 14;
        // If simulatedPit is on CPU's side and contains no Marbles
        if (simulatedPit > 7 && simulatedPit < 14 && currentMarbles[simulatedPit] == 0) {
            // simulatedEnd = Player's Pit that will be captured
            simulatedEnd = 14 - simulatedPit;
            // If more than 3 in that pocket
            if (currentMarbles[simulatedEnd] > 3) {
                return i;
            }
        }
    }

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
HardCPU::~HardCPU() {

}