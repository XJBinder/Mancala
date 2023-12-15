#include <iostream>
#include "Board.h"
#include "EasyCPU.h"
#include "MediumCPU.h"
#include "HardCPU.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	Board board;
	EasyCPU* CPU = nullptr;
	bool gameOver = false;
	int pitNumb, difficulty;
	int extraTurn = 0;

	cout << " __       __                                          __" << endl;
	cout << "/  \\     /  |                                        /  |" << endl;
	cout << "$$  \\   /$$ |  ______   _______    _______   ______  $$ |  ______" << endl;
	cout << "$$$  \\ /$$$ | /      \\ /       \\  /       | /      \\ $$ | /      \\" << endl;
	cout << "$$$$  /$$$$ | $$$$$$  |$$$$$$$  |/$$$$$$$/  $$$$$$  |$$ | $$$$$$  |" << endl;
	cout << "$$ $$ $$/$$ | /    $$ |$$ |  $$ |$$ |       /    $$ |$$ | /    $$ |" << endl;
	cout << "$$ |$$$/ $$ |/$$$$$$$ |$$ |  $$ |$$ \\_____ /$$$$$$$ |$$ |/$$$$$$$ |" << endl;
	cout << "$$ | $/  $$ |$$    $$ |$$ |  $$ |$$       |$$    $$ |$$ |$$    $$ |" << endl;
	cout << "$$/      $$/  $$$$$$$/ $$/   $$/  $$$$$$$/  $$$$$$$/ $$/  $$$$$$$/" << endl;
	cout << "\t\t\t\t\t\t\tJon Binder" << endl << endl;

	cout << "Select CPU Difficulty" << endl << " 1) Easy" << endl << " 2) Medium" << endl << " 3) Hard" << endl << ">> ";
	cin >> difficulty;

	if (difficulty == 1) {
		CPU = new EasyCPU(board);
	}
	else if (difficulty == 2) {
		CPU = new MediumCPU(board);
	}
	else if (difficulty == 3) {
		CPU = new HardCPU(board);
	}
	else {
		cout << "Invalid Input" << endl << "Default: Medium Difficulty" << endl;
		CPU = new MediumCPU(board);
	}
	cout << endl;

	board.printBoard();

	while (!gameOver) {
		// Players Turn
		do {
			// Check if gameOver == True
			gameOver = board.gameOver();
			if (gameOver) {
				break;
			}

			// Get Player Input
			cout << "Pick a Pit (1-6)" << endl << ">> ";
			cin >> pitNumb;
			while (pitNumb < 1 || pitNumb > 6 || board.checkPit(pitNumb) == 0) {
				if (board.checkPit(pitNumb) == 0) {
					cout << "Choose a Pit with Marbles!" << endl << ">> ";
				}
				else {
					cout << "Invalid Entry" << endl << ">> ";
				}
				cin >> pitNumb;
			}

			// Parameters: Chosen Pit, isCPU?
			extraTurn = board.makeMove(pitNumb, false);

			board.printBoard();

			if (extraTurn == 1) {
				cout << "Extra Turn!" << endl << endl;
			}

		} while (extraTurn == 1);

		// CPU's Turn
		do {
			gameOver = board.gameOver();
			if (gameOver) {
				break;
			}

			if (extraTurn == 1) {
				cout << "CPU Extra Turn!" << endl << endl;
			}
			else {
				cout << "CPU's Turn" << endl << endl;
			}

			// CPU looks at board
			CPU->readMarbles(board);
			// Parameters: Number between 8-13, this is CPU
			extraTurn = board.makeMove(CPU->CPUMove(), true);

			board.printBoard();
			
		} while (extraTurn == 1);
	}

	// Who's Mancala has the most Marbles
	if (board.checkPit(0) > board.checkPit(7)) {
		board.printBoard();
		cout << "CPU Won!" << endl;
	}
	else if (board.checkPit(0) < board.checkPit(7)) {
		board.printBoard();
		cout << "You Won!" << endl;
	}
	else {
		board.printBoard();
		cout << "A Tie!" << endl;
	}

	delete CPU;
	return 0;
}