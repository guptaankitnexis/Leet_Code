
class Solution {
public:
    // Main function to solve the Sudoku puzzle
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // call the helper function to solve the board
    }

    // Helper function to solve the board using backtracking
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) { // iterate through each row
            for (int j = 0; j < board[0].size(); j++) { // iterate through each column
                if (board[i][j] == '.') { // if the cell is empty
                    for (char c = '1'; c <= '9'; c++) { // try all possible digits
                        if (isValid(board, i, j, c)) { // check if the digit is valid
                            board[i][j] = c; // place the digit on the board
                            if (solve(board)) // recursively solve the rest of the board
                                return true;
                            else
                                board[i][j] = '.'; // backtrack if the solution is not valid
                        }
                    }
                    return false; // return false if no digit is valid
                }
            }
        }
        return true; // return true if the board is solved
    }

    // Function to check if placing a digit at board[row][col] is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) { // check all rows, columns, and sub-boxes
            if (board[row][i] == c) { // check the row
                return false;
            }
            if (board[i][col] == c) { // check the column
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) { // check the 3x3 sub-box
                return false;
            }
        }
        return true; // return true if the digit is valid
    }
};