#include <iostream>
using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if the game is over
bool isGameOver(char board[3][3]) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }

    return true;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;

    cout << "Welcome to Tic Tac Toe!" << endl;

    while (true) {
        printBoard(board);

        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Adjust row and col to match array indices (subtract 1)
        row--; // Decrement by 1 to match array indices
        col--;

        // Check if the input is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (isGameOver(board)) {
            printBoard(board);
            if (currentPlayer == 'X')
                cout << "Player X wins!" << endl;
            else
                cout << "Player O wins!" << endl;
            break;
        }

        // Switch to the other player
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

    return 0;
}
