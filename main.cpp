#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int boardSize = 4;  // Adjust the size of the board as needed

vector<vector<char>> initializeBoard() {
    vector<vector<char>> board(boardSize, vector<char>(boardSize, ' '));
    char symbol = 'A';

    for (int i = 0; i < boardSize / 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int row, col;
            do {
                row = rand() % boardSize;
                col = rand() % boardSize;
            } while (board[row][col] != ' ');

            board[row][col] = symbol;
        }
        symbol++;
    }

    return board;
}

void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (j > 0)
                cout << " | ";
            cout << board[i][j];
        }
        cout << endl;
        if (i < boardSize - 1)
            cout << "-----------" << endl;
    }
}

int main() {
    srand(time(0));
    vector<vector<char>> board = initializeBoard();
    vector<vector<bool>> revealed(boardSize, vector<bool>(boardSize, false));
    int pairsMatched = 0;

    while (pairsMatched < boardSize / 2) {
        displayBoard(board);

        int row1, col1, row2, col2;
        cout << "Enter the coordinates of two cards (e.g., 1 2 3 4): ";
        cin >> row1 >> col1 >> row2 >> col2;

        if (row1 < 1 || row1 > boardSize || col1 < 1 || col1 > boardSize ||
            row2 < 1 || row2 > boardSize || col2 < 1 || col2 > boardSize) {
            cout << "Invalid input. Please try again." << endl;
            continue;
        }

        row1--;
        col1--;
        row2--;
        col2;

        if (revealed[row1][col1] || revealed[row2][col2]) {
            cout << "One or both cards are already revealed. Try again." << endl;
            continue;
        }

        if (board[row1][col1] == board[row2][col2]) {
            cout << "Match found!" << endl;
            revealed[row1][col1] = true;
            revealed[row2][col2] = true;
            pairsMatched++;
        } else {
            cout << "No match. Try again." << endl;
        }
    }

    displayBoard(board);
    cout << "Congratulations! You've matched all pairs." << endl;

    return 0;
}
