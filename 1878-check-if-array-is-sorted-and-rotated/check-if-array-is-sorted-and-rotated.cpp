class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;  // To count the number of "drops"
        int n = nums.size();  // Size of the array

        for (int i = 0; i < n; i++) {
            // Check if the current element is greater than the next (circularly)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;  // Increment count if there is a "drop"
            }
            // If there is more than one "drop", return false
            if (count > 1) {
                return false;
            }
        }

        // Return true if there is at most one "drop"
        return true;
    }
};