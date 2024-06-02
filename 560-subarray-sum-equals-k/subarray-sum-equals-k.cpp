class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;  // Map to store prefix sums and their counts
        int n = nums.size();
        int preSum = 0;  // Initialize prefix sum
        int count = 0;  // Initialize count of subarrays
        mpp[0] = 1;  // Base case: one way to have a prefix sum of 0
        
        for (int i = 0; i < n; i++) {
            preSum += nums[i];  // Update prefix sum with current element
            int rem = preSum - k;  // Calculate the remainder needed for a subarray sum to k
            
            // If the remainder is found in the map, add its count to the result
            if (mpp.find(rem) != mpp.end()) {
                count += mpp[rem];
            }
            
            mpp[preSum]++;  // Increment the count of the current prefix sum in the map
        }
        return count; // Return the total count of subarrays that sum to k
    }
};