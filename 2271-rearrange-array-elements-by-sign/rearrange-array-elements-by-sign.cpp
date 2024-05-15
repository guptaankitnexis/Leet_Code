class Solution {
public:
    // Function to rearrange positive and negative integers alternatively
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); // Result vector
        int posIndex = 0; // Index to place positive integers
        int negIndex = 1; // Index to place negative integers
        for(int i = 0;i<n;i++){
            if(nums[i]<0){ // If the number is negative
                ans[negIndex] = nums[i]; // Place negative number at negIndex
                negIndex += 2; // Move to the next position for next negative number
            }
            else{ // If the number is positive
                ans[posIndex]= nums[i]; // Place positive number at posIndex
                posIndex += 2; // Move to the next position for next positive number
            }
        }
        return ans; // Return the rearranged array
    }
};