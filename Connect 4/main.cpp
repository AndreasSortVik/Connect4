#include "declear.h"

int main() {
	while (true) {
		std::cout << "If you want to play against, make player 2's name 'AI'" << std::endl;
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
		player1 = true;
		playerGame();
	}

	return 0;
}

void playerGame() {
	player1Play();

	return;
}

void player1Play() {
	while (player1 == true) {
		std::cout << "It is time for '" << playerOneName << "' to take their turn." << std::endl;
		emptyBoard();

		input = _getch();

		switch (input) {
		case 1:
			//Placement == board[6][1]
		}
		
		break;
	}

	return;
}

void player2Play() {


	return;
}

void AIGame() {
	std::cout << "AI Gameplay";

	return;
}

void emptyBoard() {
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