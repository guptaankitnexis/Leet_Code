class Solution {
public:
    vector<int> NSE(vector<int> arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> PSE(vector<int> arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        int n = heights.size();
        vector<int> nse = NSE(heights, n);
        vector<int> pse = PSE(heights, n);
        for (int i = 0; i < heights.size(); i++) {
            area = max(area, heights[i] * (nse[i] - pse[i] - 1));
        }
        return area;
    }
};