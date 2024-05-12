class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store the number needed to reach the target and its index
        map<int, int> mpp;
        int num;
        int moreNeeded;

        // Iterate through the input vector
        for(int i = 0; i < nums.size(); i++) {
            // Current number from the input vector
            num = nums[i];
            // Calculate the number needed to reach the target
            moreNeeded = target - num;

            // Check if the number needed exists in the map
            if(mpp.find(moreNeeded) != mpp.end()) {
                // If found, return the indices of the two numbers
                // that add up to the target
                return {mpp[moreNeeded], i};
            }
            // Otherwise, store the current number and its index in the map
            mpp[num] = i;
        }
        // If no solution is found, return {-1, -1}
        return {-1, -1};
    }
};