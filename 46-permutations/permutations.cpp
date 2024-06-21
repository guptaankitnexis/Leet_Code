
class Solution {
public:
    // Function to generate all permutations of the given array
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;      // To store all the permutations
        vector<int> ds;               // To store the current permutation
        int n = nums.size();          // Size of the input array
        vector<bool> freq(n, false);  // To keep track of used elements
        permutation(nums, ds, freq, ans, n); // Start the permutation generation
        return ans;
    }
    
    // Recursive function to generate permutations
    void permutation(vector<int>& nums, vector<int>& ds, vector<bool>& freq, vector<vector<int>>& ans, int n) {
        if (ds.size() == n) {  // If the current permutation is complete
            ans.push_back(ds); // Add it to the answer list
            return;
        }
        for (int i = 0; i < n; i++) {  // Iterate over each element
            if (!freq[i]) {            // If the element is not used
                freq[i] = true;        // Mark the element as used
                ds.push_back(nums[i]); // Add the element to the current permutation
                permutation(nums, ds, freq, ans, n); // Recurse to continue building the permutation
                ds.pop_back();         // Backtrack: remove the last element
                freq[i] = false;       // Unmark the element as used
            }
        }
    }
};