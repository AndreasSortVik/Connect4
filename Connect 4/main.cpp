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
	std::cout << "AI Gameplay";

	return;
}

void checkWin() {
	//Vertical wins
	for (int i = 5; i >= 0; i--) {
		for (int j = 6; j >= 0; j--) {
			//Vertical win for playerOne
			if (board[i][j] == playerOne && board[i - 1][j] == playerOne && board[i - 2][j] == playerOne && board[i - 3][j] == playerOne) {
				winner = 1;
				endGame();
			}
			//Vertical win for playerTwo
			if (board[i][j] == playerTwo && board[i - 1][j] == playerTwo && board[i - 2][j] == playerTwo && board[i - 3][j] == playerTwo) {
				winner = 2;
				endGame();
			}
		}
	}

	//Horizontal wins
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//Horizontal win for playerOne
			if (board[j][i] == playerOne && board[j][i + 1] == playerOne && board[j][i + 2] == playerOne && board[j][i + 3] == playerOne) {
				winner = 1;
				endGame();
			}
			//Horizontal win for playerTwo
			if (board[j][i] == playerTwo && board[j][i + 1] == playerTwo && board[j][i + 2] == playerTwo && board[j][i + 3] == playerTwo) {
				winner = 2;
				endGame();
			}
		}
	}

	//Diagonal wins
	for (int i = 5; i >= 0; i--) {
		for (int j = 6; j >= 0; j--) {
			//Vertical win for playerOne
			if (board[i][j] == playerOne && board[i - 1][j - 1] == playerOne && board[i - 2][j - 2] == playerOne && board[i - 3][j - 3] == playerOne) {
				winner = 1;
				endGame();
			}
			if (board[i][j] == playerOne && board[i - 1][j + 1] == playerOne && board[i - 2][j + 2] == playerOne && board[i - 3][j + 3] == playerOne) {
				winner = 1;
				endGame();
			}
			//Diagonal win for playerTwo
			if (board[i][j] == playerTwo && board[i - 1][j - 1] == playerTwo && board[i - 2][j - 2] == playerTwo && board[i - 3][j - 3] == playerTwo) {
				winner = 2;
				endGame();
			}
			if (board[i][j] == playerTwo && board[i - 1][j + 1] == playerTwo && board[i - 2][j + 2] == playerTwo && board[i - 3][j + 3] == playerTwo) {
				winner = 2;
				endGame();
			}
		}
	}

	return;
}

void endGame() {
	system("cls");
	buildBoard();

	if (winner == 1) {
		std::cout << playerOneName << " won the game." << std::endl;
		//Update and display current amount of wins for playerOne from file
	}
	if (winner == 2) {
		std::cout << playerTwoName << " won the game." << std::endl;
		//Update and display current amount of wins for playerTwo from file
	}

	exit(0); //Make it so it is possible to start a new game

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

void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');

	return;
}