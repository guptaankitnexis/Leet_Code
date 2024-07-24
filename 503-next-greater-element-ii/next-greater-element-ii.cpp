class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        vector<int> ans(n); // Initialize the answer array with the same size as input
        stack<int> st; // Stack to keep track of the next greater elements

        // Loop through the array twice to handle the circular nature
        for (int i = 2 * n - 1; i >= 0; i--) {
            // Remove elements from the stack that are less than or equal to the current element
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            // If we are in the first pass (i < n), set the answer for the current element
            if (i < n) {
                ans[i] = st.empty() ? -1 : st.top(); // If stack is empty, no greater element; else, top of stack
            }
            // Push the current element to the stack
            st.push(nums[i % n]);
        }
        return ans; // Return the result array
    }
};
