#include "connect4.h"

int main() 
{
    initializeBoard();

    cout << "Connect4!\n\n";

    while (!isGameOver()) 
    {
        printBoard();

        int col;

        cout << "Player " << currentPlayer << ", choose a column (1-7): ";
        cin >> col;

        if (dropPiece(col)) 
        {
            // Alternating players
            currentPlayer = (currentPlayer == 'X') ? 'Z' : 'X';
        }
    }

    printBoard();

    cout << "Game Over!\n\n";

    if (isGameOver()) 
    {
        cout << "Player " << ((currentPlayer == 'X') ? 'Z' : 'X') << " wins!\n";
    }
    else 
    {
        cout << "It's a draw!\n";
    }

    return 0;
}