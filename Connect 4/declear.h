#include <iostream>
#include <string>
#pragma once

#ifndef DECLEAR_H
#define DECLEAR_H

void emptyBoard();
void playerGame();
void player1Play();
void player2Play();
void AIGame();
void clearcin();

//Board variables
const int row = 7;
const int col = 17;
char board[row][col] = { {' ', ' ', '1', ' ', '2', ' ', '3', ' ', '4', ' ', '5', ' ', '6', ' ', '7', ' ', ' '},
	{'|', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '|'},
	{'|', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '|'},
	{'|', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '|'},
	{'|', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '|'},
	{'|', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '|'},
	{'|', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '|'} };

//Player variables
bool player1 = false;
bool player2 = false;
bool AI = false;
std::string playerOneName;
std::string playerTwoName;

#endif
