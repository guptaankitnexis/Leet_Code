class Solution {

    // Main method to solve N-Queens problem
    public List<List<String>> solveNQueens(int n) 
    {
        List<List<String>> listOfLists = new ArrayList<>();
        char [][] board = new char [n][n];
        int column = 0;
        placeQueen(listOfLists, board, column);
        return listOfLists;
    }
    
    // Recursive method to place queens on the board
    public void placeQueen(List<List<String>> listOfLists, char [][] board, int column)
    {
        // If all queens are placed, save the board configuration
        if(column == board.length)
        {
            saveBoard(listOfLists, board);
            return;
        }
        
        // Try placing a queen in each row of the current column
        for (int row = 0; row < board.length; row++)
        {
            if (isSafe(board, row, column)){
                // Place a queen and move to the next column
                board[row][column] = 'Q';
                placeQueen(listOfLists, board, column + 1);
                
                // Backtrack by removing the queen for other possibilities
                board[row][column] = '.';
            }
        }
    }

    // Check if it's safe to place a queen at the specified position
    public boolean isSafe(char [][] board, int row, int column)
    {
        // Check for horizontal conflicts
        for (int j = 0; j < column; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        // Check for upper left diagonal conflicts
        int r = row;
        int c = column;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;  c--;
        }

        // Check for lower left diagonal conflicts
        r = row;
        c = column;
        while(r < board.length && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r++;  c--;
        }

        // If no conflicts found, it's safe
        return true;
    }

    // Save the board configuration to the list of lists
    public void saveBoard(List<List<String>> listOfLists, char [][] board)
    {
        List<String> oneBoard = new ArrayList<>();
        for (int i = 0; i < board.length; i++)
        {
            StringBuilder row = new StringBuilder();
            for (int j = 0; j < board.length; j++)
            {
                // Append 'Q' or '.' to the current row
                if(board[i][j] == 'Q'){
                    row.append('Q');
                }
                else{
                    row.append('.');
                }
            }
            oneBoard.add(row.toString());
        }
        // Add the current board configuration to the list of lists
        listOfLists.add(oneBoard);
    }
}
