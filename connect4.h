#ifndef CONNECT4_H
#define CONNECT4_H

#include <iostream>
using namespace std;

const int ROWS = 6; // Number of rows in the board
const int COLS = 7; // Number of columns in the board
extern char board[ROWS][COLS]; // 2D array to represent the board
extern char currentPlayer; // Current player ('X' or 'O')

// Function declarations
void initializeBoard();
void printBoard();
bool dropPiece(int col);
bool checkWin(int row, int col);
bool isGameOver();

#endif // CONNECT4_H