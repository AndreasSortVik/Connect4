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
	while (true) {
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

		switch (input) {
		case '1':
			if (board[5][0] == '*') {
				board[5][0] = playerOne;
			}
			else if (board[4][0] == '*') {
				board[4][0] = playerOne;
			}
			else if (board[3][0] == '*') {
				board[3][0] = playerOne;
			}
			else if (board[2][0] == '*') {
				board[2][0] = playerOne;
			}
			else if (board[1][0] == '*') {
				board[1][0] = playerOne;
			}
			else if (board[0][0] == '*') {
				board[0][0] = playerOne;
			}
			else {
				continue;
			}
			break;
		case '2':
			if (board[5][1] == '*') {
				board[5][1] = playerOne;
			}
			else if (board[4][1] == '*') {
				board[4][1] = playerOne;
			}
			else if (board[3][1] == '*') {
				board[3][1] = playerOne;
			}
			else if (board[2][1] == '*') {
				board[2][1] = playerOne;
			}
			else if (board[1][1] == '*') {
				board[1][1] = playerOne;
			}
			else if (board[0][1] == '*') {
				board[0][1] = playerOne;
			}
			else {
				continue;
			}
			break;
		case '3':
			if (board[5][2] == '*') {
				board[5][2] = playerOne;
			}
			else if (board[4][2] == '*') {
				board[4][2] = playerOne;
			}
			else if (board[3][2] == '*') {
				board[3][2] = playerOne;
			}
			else if (board[2][2] == '*') {
				board[2][2] = playerOne;
			}
			else if (board[1][2] == '*') {
				board[1][2] = playerOne;
			}
			else if (board[0][2] == '*') {
				board[0][2] = playerOne;
			}
			else {
				continue;
			}
			break;
		case '4':
			if (board[5][3] == '*') {
				board[5][3] = playerOne;
			}
			else if (board[4][3] == '*') {
				board[4][3] = playerOne;
			}
			else if (board[3][3] == '*') {
				board[3][3] = playerOne;
			}
			else if (board[2][3] == '*') {
				board[2][3] = playerOne;
			}
			else if (board[1][3] == '*') {
				board[1][3] = playerOne;
			}
			else if (board[0][3] == '*') {
				board[0][3] = playerOne;
			}
			else {
				continue;
			}
			break;
		case '5':
			if (board[5][4] == '*') {
				board[5][4] = playerOne;
			}
			else if (board[4][4] == '*') {
				board[4][4] = playerOne;
			}
			else if (board[3][4] == '*') {
				board[3][4] = playerOne;
			}
			else if (board[2][4] == '*') {
				board[2][4] = playerOne;
			}
			else if (board[1][4] == '*') {
				board[1][4] = playerOne;
			}
			else if (board[0][4] == '*') {
				board[0][4] = playerOne;
			}
			else {
				continue;
			}
			break;
		case '6':
			if (board[5][5] == '*') {
				board[5][5] = playerOne;
			}
			else if (board[4][5] == '*') {
				board[4][5] = playerOne;
			}
			else if (board[3][5] == '*') {
				board[3][5] = playerOne;
			}
			else if (board[2][5] == '*') {
				board[2][5] = playerOne;
			}
			else if (board[1][5] == '*') {
				board[1][5] = playerOne;
			}
			else if (board[0][5] == '*') {
				board[0][5] = playerOne;
			}
			else {
				continue;
			}
			break;
		case '7':
			if (board[5][6] == '*') {
				board[5][6] = playerOne;
			}
			else if (board[4][6] == '*') {
				board[4][6] = playerOne;
			}
			else if (board[3][6] == '*') {
				board[3][6] = playerOne;
			}
			else if (board[2][6] == '*') {
				board[2][6] = playerOne;
			}
			else if (board[1][6] == '*') {
				board[1][6] = playerOne;
			}
			else if (board[0][6] == '*') {
				board[0][6] = playerOne;
			}
			else {
				continue;
			}
			break;
		default:
			continue;
		}
		
		playerOneTurn = false;
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

		switch (input) {
		case '1':
			if (board[5][0] == '*') {
				board[5][0] = playerTwo;
			}
			else if (board[4][0] == '*') {
				board[4][0] = playerTwo;
			}
			else if (board[3][0] == '*') {
				board[3][0] = playerTwo;
			}
			else if (board[2][0] == '*') {
				board[2][0] = playerTwo;
			}
			else if (board[1][0] == '*') {
				board[1][0] = playerTwo;
			}
			else if (board[0][0] == '*') {
				board[0][0] = playerTwo;
			}
			else {
				continue;
			}
			break;
		case '2':
			if (board[5][1] == '*') {
				board[5][1] = playerTwo;
			}
			else if (board[4][1] == '*') {
				board[4][1] = playerTwo;
			}
			else if (board[3][1] == '*') {
				board[3][1] = playerTwo;
			}
			else if (board[2][1] == '*') {
				board[2][1] = playerTwo;
			}
			else if (board[1][1] == '*') {
				board[1][1] = playerTwo;
			}
			else if (board[0][1] == '*') {
				board[0][1] = playerTwo;
			}
			else {
				continue;
			}
			break;
		case '3':
			if (board[5][2] == '*') {
				board[5][2] = playerTwo;
			}
			else if (board[4][2] == '*') {
				board[4][2] = playerTwo;
			}
			else if (board[3][2] == '*') {
				board[3][2] = playerTwo;
			}
			else if (board[2][2] == '*') {
				board[2][2] = playerTwo;
			}
			else if (board[1][2] == '*') {
				board[1][2] = playerTwo;
			}
			else if (board[0][2] == '*') {
				board[0][2] = playerTwo;
			}
			else {
				continue;
			}
			break;
		case '4':
			if (board[5][3] == '*') {
				board[5][3] = playerTwo;
			}
			else if (board[4][3] == '*') {
				board[4][3] = playerTwo;
			}
			else if (board[3][3] == '*') {
				board[3][3] = playerTwo;
			}
			else if (board[2][3] == '*') {
				board[2][3] = playerTwo;
			}
			else if (board[1][3] == '*') {
				board[1][3] = playerTwo;
			}
			else if (board[0][3] == '*') {
				board[0][3] = playerTwo;
			}
			else {
				continue;
			}
			break;
		case '5':
			if (board[5][4] == '*') {
				board[5][4] = playerTwo;
			}
			else if (board[4][4] == '*') {
				board[4][4] = playerTwo;
			}
			else if (board[3][4] == '*') {
				board[3][4] = playerTwo;
			}
			else if (board[2][4] == '*') {
				board[2][4] = playerTwo;
			}
			else if (board[1][4] == '*') {
				board[1][4] = playerTwo;
			}
			else if (board[0][4] == '*') {
				board[0][4] = playerTwo;
			}
			else {
				continue;
			}
			break;
		case '6':
			if (board[5][5] == '*') {
				board[5][5] = playerTwo;
			}
			else if (board[4][5] == '*') {
				board[4][5] = playerTwo;
			}
			else if (board[3][5] == '*') {
				board[3][5] = playerTwo;
			}
			else if (board[2][5] == '*') {
				board[2][5] = playerTwo;
			}
			else if (board[1][5] == '*') {
				board[1][5] = playerTwo;
			}
			else if (board[0][5] == '*') {
				board[0][5] = playerTwo;
			}
			else {
				continue;
			}
			break;
		case '7':
			if (board[5][6] == '*') {
				board[5][6] = playerTwo;
			}
			else if (board[4][6] == '*') {
				board[4][6] = playerTwo;
			}
			else if (board[3][6] == '*') {
				board[3][6] = playerTwo;
			}
			else if (board[2][6] == '*') {
				board[2][6] = playerTwo;
			}
			else if (board[1][6] == '*') {
				board[1][6] = playerTwo;
			}
			else if (board[0][6] == '*') {
				board[0][6] = playerTwo;
			}
			else {
				continue;
			}
			break;
		default:
			continue;
		}

		playerOneTurn = true;
		playerTwoTurn = false;
	}

	return;
}

void AIGame() {
	std::cout << "AI Gameplay";

	return;
}

void checkWin() {
	
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