class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> prefix(rows, vector<int>(column));
        for (int j = 0; j < matrix[0].size(); j++) {
            int sum = 0;
            for (int i = 0; i < matrix.size(); i++) {
                sum += matrix[i][j] - '0';
                if (matrix[i][j] == '0')
                    sum = 0;
                prefix[i][j] = sum;
            }
        }
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i++) {
            maxArea = max(maxArea, largestRectangleArea(prefix[i]));
        }
        return maxArea;
    }
};