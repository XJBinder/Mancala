#include "Board.h"

// Constructor
Board::Board() {
	// Initialize the array pits[]
	pits[0] = Pit(0); // 0 (CPU Mancala)
	pits[7] = Pit(0); // 7 (Player Mancala)
	// Initialize other pits with default constructor
	for (int i = 1; i < 7; ++i) {
		pits[i] = Pit();
	}
	for (int i = 8; i < 14; ++i) {
		pits[i] = Pit();
	}
}

// Methods
void Board::printBoard() {
	// Handles double digits
	cout << "\t+---------+" << endl << "\t|    " << pits[0].showMarbles();
	if (pits[0].showMarbles() < 10) {
		cout << "    |" << endl;
	}
	else {
		cout << "   |" << endl;
	}
	
	cout << "\t+----+----+" << endl << "  1)    | " << pits[1].showMarbles();
	if (pits[1].showMarbles() < 10) {
		cout << "  |";
	}
	else {
		cout << " |";
	}
	if (pits[13].showMarbles() < 10) {
		cout << "  ";
	}
	else {
		cout << " ";
	}
	cout << pits[13].showMarbles() << " |" << endl;
	
	cout << "\t+----|----+" << endl << "  2)    | " << pits[2].showMarbles();
	if (pits[2].showMarbles() < 10) {
		cout << "  |";
	}
	else {
		cout << " |";
	}
	if (pits[12].showMarbles() < 10) {
		cout << "  ";
	}
	else {
		cout << " ";
	}
	cout << pits[12].showMarbles() << " |" << endl;
	
	cout << "\t+----|----+" << endl << "  3)    | " << pits[3].showMarbles();
	if (pits[3].showMarbles() < 10) {
		cout << "  |";
	}
	else {
		cout << " |";
	}
	if (pits[11].showMarbles() < 10) {
		cout << "  ";
	}
	else {
		cout << " ";
	}
	cout << pits[11].showMarbles() << " |" << endl;
	
	cout << "\t+----|----+" << endl << "  4)    | " << pits[4].showMarbles();
	if (pits[4].showMarbles() < 10) {
		cout << "  |";
	}
	else {
		cout << " |";
	}
	if (pits[10].showMarbles() < 10) {
		cout << "  ";
	}
	else {
		cout << " ";
	}
	cout << pits[10].showMarbles() << " |" << endl;
	
	cout << "\t+----|----+" << endl << "  5)    | " << pits[5].showMarbles();
	if (pits[5].showMarbles() < 10) {
		cout << "  |";
	}
	else {
		cout << " |";
	}
	if (pits[9].showMarbles() < 10) {
		cout << "  ";
	}
	else {
		cout << " ";
	}
	cout << pits[9].showMarbles() << " |" << endl;
	
	cout << "\t+----|----+" << endl << "  6)    | " << pits[6].showMarbles();
	if (pits[6].showMarbles() < 10) {
		cout << "  |";
	}
	else {
		cout << " |";
	}
	if (pits[8].showMarbles() < 10) {
		cout << "  ";
	}
	else {
		cout << " ";
	}
	cout << pits[8].showMarbles() << " |" << endl << "\t+----+----+" << endl;
	if (pits[7].showMarbles() < 10) {
		cout << "\t|    " << pits[7].showMarbles();
	}
	else {
		cout << "\t|   " << pits[7].showMarbles();
	}
	cout << "    |" << endl << "\t+---------+" << endl << endl;
}

int Board::makeMove(int pitNumb, bool CPU) {
	int pitsToMove, currentPit, captured, oppositePit;

	// Determines which Mancala to skip and which to add to
	int home = 8;
	int away = 0;
	if (CPU) {
		home = 1;
		away = 7;
	}
	
	// pitsToMove = number of marbles in picked pit
	pitsToMove = pits[pitNumb].showMarbles();
	// Empty pit that was picked
	pits[pitNumb].setMarbles(0);

	currentPit = pitNumb + 1;
	for (int i = 0; i < pitsToMove; i++) {
		// Wrap around the board when the index of pits gets above 13
		currentPit = (currentPit) % 14;

		// Skip opponent's Mancala at index "away" (Player:0, CPU: 7)
		if (currentPit == away) {
			currentPit = 1;
		}

		// Place one marble in the current pit
		pits[currentPit].setMarbles(pits[currentPit].showMarbles() + 1);
		
		// Goto next Pit
		currentPit++;
	}

	// If last Marble lands in a Mancala (Player: 8, CPU: 1), extra turn
	if (currentPit == home) {
		return 1;
	}

	// If last Marble lands in an empty Pit
	if (pits[currentPit - 1].showMarbles() == 1) {
		// Pit to capture
		oppositePit = 14 - (currentPit - 1);
		
		// If its the player's turn && on the players side && the pit to capture contains marbles
		if (!CPU && currentPit > 1 && currentPit <= 7 && pits[oppositePit].showMarbles() > 0) {
			captured = pits[oppositePit].showMarbles(); // captured = the number of marbles in oppositePit
			pits[7].setMarbles(pits[7].showMarbles() + captured + 1); // Add captured to Player's Mancala
			// Set both Player and CPU pocket to zero
			pits[oppositePit].setMarbles(0);
			pits[currentPit - 1].setMarbles(0);
		}
		// If its the CPU's turn && on the CPU's side && the pit to capture contains marbles
		else if (CPU && currentPit >= 8 && currentPit < 15 && pits[oppositePit].showMarbles() > 0) {
			captured = pits[oppositePit].showMarbles(); // captured = the number of marble in oppositePit
			pits[0].setMarbles(pits[0].showMarbles() + captured + 1); // Add captured to CPU's Mancala
			// Set both CPU and Player pockets to zero
			pits[oppositePit].setMarbles(0);
			pits[currentPit - 1].setMarbles(0);
		}
		return 0;
	}
	else {
		return 0;
	}
}

// Returns int Marbles in given Pit
int Board::checkPit(int pitNumb) {
	return pits[pitNumb].showMarbles();
}

bool Board::gameOver() {
	// Check Player's side
	int count = 0;
	for (int i = 1; i < 7; i++) {
		if (pits[i].showMarbles() == 0) {
			count++; // Increase counter if Pit is empty
		}
	}
	// If every Player Pit is empty gameOver = TRUE
	if (count == 6) {
		count = 0;
		// Add all Marbles on CPU's side
		for (int i = 8; i < 14; i++) {
			count += pits[i].showMarbles();
			pits[i].setMarbles(0);
		}
		// Add Marbles to CPU's Mancala
		pits[0].setMarbles(pits[0].showMarbles() + count);

		return true;
	}

	// Check CPU's side
	count = 0;
	for (int i = 8; i < 14; i++) {
		if (pits[i].showMarbles() == 0) {
			count++; // Increase counter if Pit is empty
		}
	}
	// If every CPU Pit is empty gameOver = TRUE
	if (count == 6) {
		count = 0;
		// Add all Marbles on Player's side
		for (int i = 1; i < 7; i++) {
			count += pits[i].showMarbles();
			pits[i].setMarbles(0);
		}
		// Add Marbles to Player's Mancala
		pits[7].setMarbles(pits[7].showMarbles() + count);

		return true;
	}

	return false;
}

// Destructor
Board::~Board() {

}