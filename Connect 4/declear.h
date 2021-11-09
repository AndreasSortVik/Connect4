#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#pragma once

#ifndef DECLEAR_H
#define DECLEAR_H

void playerGame();
void player1Play();
void player2Play();
void AIGame();
void checkWin();
void endGame();
void buildBoard();
void clearcin();

//Board variables
std::string numbers = "  1 2 3 4 5 6 7  ";
const int row = 6;
const int col = 7;
char board[row][col] = { {'*', '*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*', '*'},
						{'*', '*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*', '*'}, 
						{'*', '*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*', '*'} };

//Player variables
bool playerOneTurn = false;
bool playerTwoTurn = false;
bool AI = false;
int input;
char playerOne = 'X';
char playerTwo = '0';
std::string playerOneName;
std::string playerTwoName;

//AI variables


//Check win variables
int winner{}; //If winner = 1, playerOne won. If winner = 2, playerTwo won

#endif
