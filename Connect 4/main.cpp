#include "declear.h"

int main() {
	std::cout << "If you want to play against, make player 2's name 'AI'" << std::endl;
	std::cout << "Player 1 name: ";
	getline(std::cin, playerOneName);
	std::cout << "Player 2 name: ";
	getline(std::cin, playerTwoName);

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
	while (player1 == true) {
		emptyBoard();
		
	}

	return;
}

void player1Play();

void AIGame() {
	std::cout << "AI Gameplay";

	return;
}

void emptyBoard() {
	std::cout << std::endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}

	return;
}

void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');

	return;
}