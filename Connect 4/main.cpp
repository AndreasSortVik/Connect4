#include "declear.h"

int main() {
	std::srand(std::time(nullptr));
	while (true) {
		std::cout << "If you want to play against AI, make player 2's name 'AI'" << std::endl;
		std::cout << "Player 1 name: ";
		getline(std::cin, playerOneName);
		std::cout << "Player 2 name: ";
		getline(std::cin, playerTwoName);

		//Makes sure name cannot be the same, so player will not get confused as to which turn it is
		if (playerOneName == playerTwoName) {
			system("cls");
			std::cout << "You cannot have the same name. Please try again." << std::endl;
			continue;
		}
		else {
			break;
		}
	}

	if (playerTwoName == "AI" || playerTwoName == "ai" || playerTwoName == "aI" || playerTwoName == "Ai") {
		system("cls");
		playerOneTurn = true;
		AIGame();
	}
	else {
		system("cls");
		playerOneTurn = true;
		playerGame();
	}

	return 0;
}

void playerGame() {
	while (true) {
		player1Play();
		checkWin();
		player2Play();
		checkWin();
	}

	return;
}

void player1Play() {
	while (playerOneTurn == true) {
		system("cls");
		std::cout << "It is time for " << playerOneName << " to take their turn." << std::endl;
		buildBoard();

		input = _getch();

		/*This for-loop checks if a placement in the board is '*'. If it is, it will place the player's character. If not,
		it will get the player to pick a column again.*/
		for (int i = 5; i >= 0; i--) {
			if (board[i][input - 49] == '*') {
				board[i][input - 49] = playerOne;
				playerOneTurn = false;
				break;
			}
			else {
				playerOneTurn = true;
				continue;
			}
		}

		playerTwoTurn = true;
		
	}

	return;
}

void player2Play() {
	while (playerTwoTurn == true) {
		system("cls");
		std::cout << "It is time for " << playerTwoName << " to take their turn." << std::endl;
		buildBoard();

		input = _getch();

		/*This for-loop checks if a placement in the board is '*'. If it is, it will place the player's character. If not,
		it will get the player to pick a column again.*/
		for (int i = 5; i >= 0; i--) {
			if (board[i][input - 49] == '*') {
				board[i][input - 49] = playerTwo;
				playerTwoTurn = false;
				break;
			}
			else {
				playerTwoTurn = true;
				continue;
			}
		}

		playerOneTurn = true;
	}

	return;
}

void AIGame() {
	while (true) {
		player1Play();
		checkWin();
		AIPlay();
		checkWin();
	}

	return;
}

void AIPlay() {
	while (playerTwoTurn == true) {
		system("cls");
		std::cout << "It is time for " << playerTwoName << " to take their turn." << std::endl;
		buildBoard();

		Sleep(1000);
		input = rand() % 7 + 1;

		for (int i = 5; i >= 0; i--) {
			if (board[i][input - 1] == '*') {
				board[i][input - 1] = playerTwo;
				playerTwoTurn = false;
				break;
			}
			else {
				playerTwoTurn = true;
				continue;
			}
		}

		playerOneTurn = true;
	}

	return;
}

void checkWin() {
	//Vertical wins
	for (int i = 5; i >= 0; i--) {
		for (int j = 6; j >= 0; j--) {
			//Vertical win for playerOne
			if (board[i][j] == playerOne && board[i - 1][j] == playerOne && board[i - 2][j] == playerOne && board[i - 3][j] == playerOne) {
				winner = 1;
				winFile();
				endGame();
			}
			//Vertical win for playerTwo
			if (board[i][j] == playerTwo && board[i - 1][j] == playerTwo && board[i - 2][j] == playerTwo && board[i - 3][j] == playerTwo) {
				winner = 2;
				winFile();
				endGame();
			}
		}
	}

	//Horizontal wins
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//Horizontal win for playerOne
			if (board[i][j] == playerOne) {
				countPlayOne++;
				if (countPlayOne == 4) {
					winner = 1;
					winFile();
					endGame();
				}
			}
			else {
				countPlayOne = 0;
			}
			//Horizontal win for playerTwo
			if (board[i][j] == playerTwo) {
				countPlayTwo++;
				if (countPlayTwo == 4) {
					winner = 2;
					winFile();
					endGame();
				}
			}
			else {
				countPlayTwo = 0;
			}
		}
	}

	//Diagonal wins
	for (int i = 5; i >= 0; i--) {
		for (int j = 6; j >= 0; j--) {
			//Vertical wins for playerOne
			if (board[i][j] == playerOne && board[i - 1][j - 1] == playerOne && board[i - 2][j - 2] == playerOne && board[i - 3][j - 3] == playerOne) {
				winner = 1;
				winFile();
				endGame();
			}
			if (board[i][j] == playerOne && board[i - 1][j + 1] == playerOne && board[i - 2][j + 2] == playerOne && board[i - 3][j + 3] == playerOne) {
				winner = 1;
				winFile();
				endGame();
			}
			//Diagonal wins for playerTwo
			if (board[i][j] == playerTwo && board[i - 1][j - 1] == playerTwo && board[i - 2][j - 2] == playerTwo && board[i - 3][j - 3] == playerTwo) {
				winner = 2;
				winFile();
				endGame();
			}
			if (board[i][j] == playerTwo && board[i - 1][j + 1] == playerTwo && board[i - 2][j + 2] == playerTwo && board[i - 3][j + 3] == playerTwo) {
				winner = 2;
				winFile();
				endGame();
			}
		}
	}

	//Game draw
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == '*') {
				charCount++;
			}
		}
	}

	if (charCount == 0) {
		winner = 3;
		endGame();
	}

	charCount = 0;

	return;
}

void endGame() {
	system("cls");
	std::cout << std::endl;
	buildBoard();

	if (winner == 1) {
		std::cout << playerOneName << " won the game." << std::endl;
		std::cout << playerOneName << " has " << playerOneWins << " wins." << std::endl;
	}
	if (winner == 2) {
		std::cout << playerTwoName << " won the game." << std::endl;
		std::cout << playerTwoName << " has " << playerTwoWins << " wins." << std::endl;
	}
	if (winner == 3) {
		std::cout << "The game has come to a draw" << std::endl;
	}
	
	std::cout << "Do you want to play again? (y/n): ";
	while (true) {
		repeatAns = _getch();

		if (repeatAns == 'y') {
			system("cls");
			resetVariables();
			if (playerTwoName == "AI" || playerTwoName == "ai" || playerTwoName == "aI" || playerTwoName == "Ai") {
				playerOneTurn = true;
				playerTwoTurn = false;
				AIGame();
			}
			else {
				playerOneTurn = true;
				playerTwoTurn = false;
				playerGame();
			}
		}
		else if (repeatAns == 'n') {
			std::cout << std::endl << std::endl;
			std::cout << playerOneName << " got " << playerOneWins << " wins." << std::endl;
			std::cout << playerTwoName << " got " << playerTwoWins << " wins." << std::endl;
			saveWins.close();
			exit(0);
		}
		else {
			continue;
		}
	}

	return;
}

void winFile() {
	if (winner == 1) {
		playerOneWins++;

		saveWins.seekp(0);
		saveWins << playerOneWins << std::endl;
	}
	else if (winner == 2) {
		playerTwoWins++;

		saveWins.seekp(0, saveWins.end);
		saveWins << playerTwoWins;
	}

	return;
}

void buildBoard() {
	std::cout << std::endl;
	std::cout << numbers << std::endl;
	for (int i = 0; i < row; i++) {
		std::cout << "|";
		for (int j = 0; j < col; j++) {
			std::cout << " " << board[i][j];
		}
		std::cout << " |" << std::endl;
	}

	return;
}

void resetVariables() {
	//Board variables
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = '*';
		}
	}

	//Player variables
	bool playerOneTurn = false;
	bool playerTwoTurn = false;

	//AI variables
	bool AI = false;

	//Win variables
	int winner{};
	int countPlayOne = 0;
	int countPlayTwo = 0;
	int charCount = 0;

	return;
}

void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');

	return;
}