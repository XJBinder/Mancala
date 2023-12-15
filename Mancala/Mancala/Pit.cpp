#include "Pit.h"

// Constructor
Pit::Pit() {
	marbles = 4;
}

Pit::Pit(int setMarbles) {
	marbles = setMarbles;
}

// Methods
int Pit::showMarbles() {
	return marbles;
}

void Pit::setMarbles(int setMarbles) {
	marbles = setMarbles;
}

// Destructor
Pit::~Pit() {

}