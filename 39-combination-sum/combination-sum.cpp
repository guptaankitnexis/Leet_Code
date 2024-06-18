class Solution {
public:
    // Helper function to find all unique combinations
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if (ind == arr.size()) { // Base case: reached the end
            if (target == 0) { // Valid combination found
                ans.push_back(ds);
            }
            return;
        }

        if (arr[ind] <= target) { // Include current element if it fits
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds); // Recur with same index
            ds.pop_back(); // Backtrack
        }

        findCombination(ind + 1, target, arr, ans, ds); // Exclude current element
    }

    // Main function to start the combination finding process
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // Final result
        vector<int> ds; // Current combination
        findCombination(0, target, candidates, ans, ds); // Start recursion
        return ans; // Return all combinations
    }
};