class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // to store all possible solutions
        vector<string> board(n); // to represent the chess board
        string s(n, '.'); // to initialize each row with '.'
        for (int i = 0; i < n; i++) {
            board[i] = s; // initialize the board with n strings of n dots
        }
        vector<bool> leftRow(n, false); // to mark the presence of a queen in each row
        vector<bool> upperDiagonal(2 * n - 1, false); // to mark the presence of a queen in upper diagonals
        vector<bool> lowerDiagonal(2 * n - 1, false); // to mark the presence of a queen in lower diagonals
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); // start solving from the first column
        return ans; // return all possible solutions
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<bool> &leftRow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal, int n) {
        // base case: if all columns are filled, store the solution
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            // check if it's safe to place a queen at board[row][col]
            if (leftRow[row] == false && upperDiagonal[n - 1 + col - row] == false && lowerDiagonal[row + col] == false) {
                board[row][col] = 'Q'; // place the queen
                leftRow[row] = true; // mark the row as occupied
                upperDiagonal[n - 1 + col - row] = true; // mark the upper diagonal as occupied
                lowerDiagonal[row + col] = true; // mark the lower diagonal as occupied
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); // move to the next column
                board[row][col] = '.'; // remove the queen (backtrack)
                leftRow[row] = false; // unmark the row
                upperDiagonal[n - 1 + col - row] = false; // unmark the upper diagonal
                lowerDiagonal[row + col] = false; // unmark the lower diagonal
            }
        }
    }
};