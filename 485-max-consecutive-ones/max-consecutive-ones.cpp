class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0; // Maximum consecutive ones
        int count = 0; // Current consecutive ones count
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                count++; // Increment count if current element is 1
                maxi = max(count, maxi); // Update maximum count
            }
            else {
                count = 0; // Reset count if current element is not 1
            }
        }
        return maxi; // Return maximum count of consecutive ones
    }
};
