#include "declear.h"

int main() {
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
	while (endGame == false) {
		player1Play();
		player2Play();
	}

	return;
}

void player1Play() {
	while (playerOneTurn == true) {
		system("cls");
		std::cout << "It is time for '" << playerOneName << "' to take their turn." << std::endl;
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

		checkWin();
		playerTwoTurn = true;
		
	}

	return;
}

void player2Play() {
	while (playerTwoTurn == true) {
		system("cls");
		std::cout << "It is time for '" << playerTwoName << "' to take their turn." << std::endl;
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

		checkWin();
		playerOneTurn = true;
	}

	return;
}

void AIGame() {
	std::cout << "AI Gameplay";

	return;
}

void checkWin() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == playerOne || board[i][j] == playerTwo) {
				changedPieces++;
			}
		}
	}
	if (changedPieces == 42) {
		std::cout << "The game came to a draw" << std::endl;
		endGame = true;
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

void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');

	return;
}