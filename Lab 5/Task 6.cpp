#include <iostream>
using namespace std;

#define SIZE 5

bool canMove(int r, int c, int maze[SIZE][SIZE], int used[SIZE][SIZE]) {
    return (r >= 0 && r < SIZE && c >= 0 && c < SIZE && maze[r][c] == 1 && !used[r][c]);
}

bool exploreMaze(int r, int c, int maze[SIZE][SIZE], int used[SIZE][SIZE], int path[SIZE][SIZE]) {
    if (r == SIZE - 1 && c == SIZE - 1) {
        path[r][c] = 1;
        return true;
    }

    if (canMove(r, c, maze, used)) {
        used[r][c] = 1;
        path[r][c] = 1;

        if (exploreMaze(r + 1, c, maze, used, path)) return true; // down
        if (exploreMaze(r, c + 1, maze, used, path)) return true; // right
        if (exploreMaze(r - 1, c, maze, used, path)) return true; // up
        if (exploreMaze(r, c - 1, maze, used, path)) return true; // left

        path[r][c] = 0;
        used[r][c] = 0;
    }
    return false;
}

void runMaze(int maze[SIZE][SIZE]) {
    int path[SIZE][SIZE] = {0};
    int used[SIZE][SIZE] = {0};

    if (!exploreMaze(0, 0, maze, used, path)) {
        cout << "No route available" << endl;
    } else {
        cout << "Maze solution:\n";
        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                cout << path[r][c] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int maze[SIZE][SIZE] = {
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1}
    };

    runMaze(maze);
    return 0;
}
