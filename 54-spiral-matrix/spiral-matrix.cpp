class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns
        int left = 0; // Left boundary
        int right = n - 1; // Right boundary
        int top = 0; // Top boundary
        int bottom = m - 1; // Bottom boundary
        vector<int> ans; // Result vector to store the spiral order
        while (top <= bottom && left <= right) {
            // Traverse top row from left to right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++; // Move top boundary down

            // Traverse right column from top to bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Move right boundary left

            // Traverse bottom row from right to left if there's still rows remaining
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Move bottom boundary up
            }

            // Traverse left column from bottom to top if there's still columns remaining
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Move left boundary right
            }
        }
        return ans; // Return the spiral order
    }
};