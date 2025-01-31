#include <iostream>
#include<time.h>
using namespace std;
void printBoard(int board[][10], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                cout << "Q "; 
            } else {
                cout << ". ";  // Empty space 
            }
        }
        cout << endl;
    }
    cout << endl;
}
// Function to check if it's safe
bool isSafe(int board[][10], int row, int col, int N) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;  // Queen already in same column
        }
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;  // Queen already placed in upper-left diagonal
        }
    }
    //check for upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;  // Queen already placed in upper right
        }
    }

    return true;
}
bool solveNQueens(int board[][10], int row, int N) {
    // If all queens are placed, return true
    if (row >= N) {
        return true;
    }
    for (int col = 0; col < N; col++) {
        // Check if it's safe to place a queen at (row, col)
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;  // Place 
            // Recur to place queens in the next row
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }
            // Backtrack: remove the queen
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    clock_t start,end;
    start=clock();
    int N;
    cout << "Enter the value of N (size of the board): ";
    cin >> N;
    int board[10][10] = {0};
    if (solveNQueens(board, 0, N)) {
        cout << "Solution to the " << N << "-Queens problem:\n";
        printBoard(board, N);
    } else {
        cout << "No solution exists for N = " << N << endl;
    }
    end=clock();
    float clk=end-start;
    cout<<"THE TIME TAKEN IS : "<<clk/CLOCKS_PER_SEC<<endl;
    return 0;
}
