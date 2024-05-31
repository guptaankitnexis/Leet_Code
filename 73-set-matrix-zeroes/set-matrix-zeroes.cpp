class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1; // To track if the first column needs to be zeroed
        int m = matrix.size();
        int n = matrix[0].size();

        // First pass: mark rows and columns that need to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the row
                    if (j == 0) {
                        col0 = 0; // Mark the first column separately
                    } else {
                        matrix[0][j] = 0; // Mark the column
                    }
                }
            }
        }

        // Second pass: update the matrix using the marks without considering the first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0; // Set to zero based on marks
                }
            }
        }

        // Update the first row if needed
        if (matrix[0][0] == 0) {
            for (int j = 1; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Update the first column if needed
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};