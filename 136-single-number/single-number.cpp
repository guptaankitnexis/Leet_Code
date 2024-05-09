class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0; // Initialize result to store XOR
        for(int i = 0; i < nums.size(); i++) {
            result ^= nums[i]; // Perform XOR operation
        }
        return result; // Return the result
    }
};
