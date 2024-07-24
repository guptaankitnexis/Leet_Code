class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size(); // Get the size of the input array
        vector<int> ans(n); // Initialize the answer array with the same size as input
        stack<int> st; // Stack to keep track of the next smaller or equal prices

        // Loop through the array from the end to the beginning
        for (int i = n - 1; i >= 0; i--) {
            // Remove elements from the stack that are greater than the current price
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            // If stack is empty, no discount; else, discount is the current price minus the top of stack
            ans[i] = st.empty() ? prices[i] : prices[i] - st.top();
            // Push the current price to the stack
            st.push(prices[i]);
        }
        return ans; // Return the result array with final prices after discounts
    }
};
