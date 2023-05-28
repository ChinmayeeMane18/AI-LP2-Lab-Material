#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    // Check if the current position is under attack from any previous queens
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || board[i] - col == i - row || board[i] - col == row - i) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<vector<string>>& solutions, vector<int>& board, int row, int n) {
    if (row == n) {
        // Found a valid solution, convert the board configuration into strings
        vector<string> solution;
        for (int i = 0; i < n; ++i) {
            string rowStr(n, '.');
            rowStr[board[i]] = 'Q';
            solution.push_back(rowStr);
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(solutions, board, row + 1, n);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<int> board(n, -1);
    solveNQueens(solutions, board, 0, n);
    return solutions;
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);
    int numSolutions = solutions.size();

    cout << "Number of solutions: " << numSolutions << endl << endl;

    // Print each solution
    for (int i = 0; i < numSolutions; ++i) {
        cout << "Solution " << i + 1 << ":\n";
        for (const auto& row : solutions[i]) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
