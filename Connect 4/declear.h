#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <fstream>
#pragma once

#ifndef DECLEAR_H
#define DECLEAR_H

void playerGame();
void player1Play();
void player2Play();
void AIGame();
void AIPlay();
void checkWin();
void endGame();
void winFile();
void buildBoard();
void resetVariables();
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
int input;
char playerOne = 'X';
char playerTwo = '0';
char repeatAns;
std::string playerOneName;
std::string playerTwoName;

//AI variables
bool breaking = false;

//Win variables
int winner{}; //If winner = 1, playerOne won. If winner = 2, playerTwo won. If winner = 3, game is a draw
int countPlayOne = 0;
int countPlayTwo = 0;
int charCount = 0;

//File variables
std::ofstream saveWins(/*"C:\\Users\\wohal\\source\\repos\\Connect4\\wins.txt"*/); //Set your desired file path here
int playerOneWins = 0;
int playerTwoWins = 0;

#endif
