class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;  // Initialize left pointer
        int right = nums.size() - 1;  // Initialize right pointer
        
        // Binary search loop
        while(left <= right){
            int mid = (left + right) / 2;  // Find the middle index
            
            if(nums[mid] == target){  // If target is found, return its index
                return mid;
            }
            else if(nums[mid] < target){  // If target is greater, ignore the left half
                left = mid + 1;
            }
            else{  // If target is smaller, ignore the right half
                right = mid - 1;
            }
        }
        return -1;  // If target is not found, return -1
    }
};