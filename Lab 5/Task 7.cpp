#include <iostream>
using namespace std;

#define LIMIT 20  

bool safeSpot(int board[LIMIT][LIMIT], int row, int col, int n) {
    for (int r = 0; r < row; r++)
        if (board[r][col]) return false;

    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
        if (board[r][c]) return false;

    for (int r = row, c = col; r >= 0 && c < n; r--, c++)
        if (board[r][c]) return false;

    return true;
}

void displayBoard(int board[LIMIT][LIMIT], int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << (board[r][c] ? "Q " : "- ");
        }
        cout << endl;
    }
    cout << endl;
}

void placeQueens(int board[LIMIT][LIMIT], int row, int n) {
    if (row == n) {
        displayBoard(board, n);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (safeSpot(board, row, c, n)) {
            board[row][c] = 1;
            placeQueens(board, row + 1, n);
            board[row][c] = 0;
        }
    }
}

void solveQueens(int n) {
    int board[LIMIT][LIMIT] = {0};
    placeQueens(board, 0, n);
}

int main() {
    int n;
    cout << "Enter size of board: ";
    cin >> n;

    if (n > LIMIT) {
        cout << "Value too large! Max. number supported: " << LIMIT << endl;
        return 0;
    }

    solveQueens(n);
    return 0;
}
