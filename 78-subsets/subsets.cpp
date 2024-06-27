class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;  // This will store all subsets
        vector<int> ds;  // This will store the current subset
        solve(0, nums, ds, ans);  // Start the recursive process
        return ans;  // Return the list of all subsets
    }

    void solve(int i, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        if (i >= nums.size()) {  // If we've considered all elements
            ans.push_back(ds);  // Add the current subset to the answer
            return;  // Backtrack
        }
        // Include the current element
        ds.push_back(nums[i]);
        solve(i + 1, nums, ds, ans);  // Move to the next element
        ds.pop_back();  // Backtrack: remove the current element

        // Exclude the current element
        solve(i + 1, nums, ds, ans);  // Move to the next element
    }
};