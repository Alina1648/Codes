#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

// Function to display the board with proper lines
void displayBoard() {
    cout << "Current Board: \n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << " " << board[i][j];
            if (j < SIZE - 1) cout << " |";  // Add vertical line between columns
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "---|---|---\n";  // Add horizontal line between rows
    }
}

// Function to check if a move is valid
bool isValidMove(int move) {
    return board[(move-1) / SIZE][(move-1) % SIZE] != 'X' && board[(move-1) / SIZE][(move-1) % SIZE] != 'O';
}

// Function to update the board with player or CPU move
void makeMove(int move, char player) {
    board[(move-1) / SIZE][(move-1) % SIZE] = player;
}

// Function to check for a win condition
bool checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full (draw)
bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function for the CPU to make an easy random move
void cpuMove() {
    srand(time(0));
    int move;
    do {
        move = rand() % 9 + 1;
    } while (!isValidMove(move));
    makeMove(move, 'O');
}

int main() {
    int move;
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe (Player vs CPU)\n";
    displayBoard();

    while (!gameOver) {
        // Player's move
        do {
            cout << "Enter your move (1-9): ";
            cin >> move;
        } while (!isValidMove(move));

        makeMove(move, 'X');
        displayBoard();

        if (checkWin('X')) {
            cout << "Congratulations! You win!\n";
            break;
        }

        if (isDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        // CPU's move
        cpuMove();
        cout << "CPU made a move:\n";
        displayBoard();

        if (checkWin('O')) {
            cout << "CPU wins! Better luck next time!\n";
            break;
        }

        if (isDraw()) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}

