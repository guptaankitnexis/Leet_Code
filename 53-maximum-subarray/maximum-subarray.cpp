class Solution {
public:
    // Function to find the maximum subarray sum
    int maxSubArray(std::vector<int>& nums) {
        // Initializing the maximum sum and the current sum
        int maxi = INT_MIN; // Initializing to the smallest possible integer
        int sum = 0;
        // Iterating through the array
        for(int i = 0; i < nums.size(); i++) {
            // Adding the current element to the sum
            sum += nums[i];
            // If the current sum is greater than the maximum sum so far
            if(sum > maxi) {
                // Update the maximum sum
                maxi = sum;
            }
            // Alternative way to update maximum sum:
            // maxi = max(sum, maxi);
            // If the sum becomes negative, reset it to 0
            if(sum < 0) {
                sum = 0;
            }
        }
        // Return the maximum sum found
        return maxi;
    }
};
