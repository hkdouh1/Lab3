#include "connect4.h"

char board[ROWS][COLS]; // 2D array
char currentPlayer = 'X'; // players ('X' or 'Z')

// creating the board
void initializeBoard() 
{
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            board[i][j] = ' '; 
        }
    }
}

//printing board function
void printBoard() 
{
    for (int i = 0; i < ROWS; ++i) 
    {
        cout << "|";

        for (int j = 0; j < COLS; ++j) 
        {
            cout << board[i][j] << "|";
        }
        cout << "\n";
    }
    cout << "-";

    for (int i = 0; i < COLS; ++i) 
    {
        cout << "--";
    }

    cout << "\n ";

    for (int i = 0; i < COLS; ++i) 
    {
        cout << i << " ";
    }
    cout << "\n";
}

// dropping a piece on the board
bool dropPiece(int col) 
{
    if (col < 0 || col >= COLS) 
    {
        cout << "Invalid column number. Try again.\n";

        return false;
    }

   
    for (int row = ROWS - 1; row >= 0; --row) 
    {
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            return true; 
        }
    }

    cout << "Column is full. Try again.\n";
    return false; 
}

// checking for a win
bool checkWin(int row, int col) 
{
    char player = board[row][col];

    // Check horizontal
    int count = 0;

    for (int c = 0; c < COLS; ++c) 
    {
        if (board[row][c] == player) 
        {
            ++count;

            if (count == 4) return true;
        }
        else 
        {
            count = 0;
        }
    }

    // vertical rows
    count = 0;

    for (int r = 0; r < ROWS; ++r) 
    {
        if (board[r][col] == player) 
        {
            ++count;

            if (count == 4) return true;
        }
        else 
        {
            count = 0;
        }
    }

    // Check diagonal (down-right)
    count = 0;

    for (int r = 0; r < ROWS; ++r) 
    {
        for (int c = 0; c < COLS; ++c) 
        {
            if (r - row == c - col && board[r][c] == player) 
            {
                ++count;

                if (count == 4) return true;
            }
        }
    }

    // Check diagonal (down-left)
    count = 0;

    for (int r = 0; r < ROWS; ++r) 
    {
        for (int c = 0; c < COLS; ++c) 
        {
            if (r - row == col - c && board[r][c] == player) 
            {
                ++count;

                if (count == 4) return true;
            }
        }
    }

    return false;
}

// checking if the game is over
bool isGameOver() 
{
    // checking for a win
    for (int row = 0; row < ROWS; ++row) 
    {
        for (int col = 0; col < COLS; ++col) 
        {
            if (board[row][col] != ' ' && checkWin(row, col)) 
            {
                return true;
            }
        }
    }

    // checking for a draw
    for (int row = 0; row < ROWS; ++row) 
    {
        for (int col = 0; col < COLS; ++col) 
        {
            if (board[row][col] == ' ') 
            {
                return false; // There are still empty spaces
            }
        }
    }

    return true;
}