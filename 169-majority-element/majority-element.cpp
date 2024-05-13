class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0; // Initialize count of current element
        int element; // Variable to store the majority element
        
        // Iterate through the vector
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) { // If count is 0, set current element as potential majority element
                element = nums[i];
                count++;
            }
            else if(element == nums[i]) { // If current element equals potential majority element, increase count
                count++;
            }
            else { // If current element is different from potential majority element, decrease count
                count--;
            }
        }
        
        return element; // Return the majority element
    }
};