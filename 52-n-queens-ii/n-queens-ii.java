class Solution {
    
    // Main method to count the total number of solutions for N-Queens
    public int totalNQueens(int n) {
        char [][] board = new char [n][n];
        int column = 0;
        int count = 0;
        count = placeQueen(board, column, count);
        return count;
    }
    
    // Recursive method to place queens on the board and count solutions
    public int placeQueen(char [][] board, int column, int count) {
        // If all queens are placed, increment the count and return
        if (column == board.length) {
            count++;
            return count;
        }
        
        // Try placing a queen in each row of the current column
        for (int row = 0; row < board.length; row++) {
            if (isSafe(board, row, column)){
                // Place a queen and move to the next column
                board[row][column] = 'Q';
                count = placeQueen(board, column + 1, count);
                
                // Backtrack by removing the queen for other possibilities
                board[row][column] = '.';
            }
        }
        return count;
    }

    // Check if it's safe to place a queen at the specified position
    public boolean isSafe(char [][] board, int row, int column) {
        // Check for horizontal conflicts
        for (int j = 0; j < column; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        // Check for upper left diagonal conflicts
        int r = row;
        int c = column;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;  c--;
        }

        // Check for lower left diagonal conflicts
        r = row;
        c = column;
        while (r < board.length && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r++;  c--;
        }

        // If no conflicts found, it's safe
        return true;
    }
}