class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;          // Initialize the low index pointer
        int mid = 0;          // Initialize the mid index pointer
        int high = nums.size() - 1;  // Initialize the high index pointer

        // Traverse the array until mid pointer crosses the high pointer
        while(mid <= high){
            // If the current element is 0, swap it with the element at low index
            // Move both low and mid pointers to the right
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            // If the current element is 1, move mid pointer to the right
            else if(nums[mid] == 1){
                mid++;
            }
            // If the current element is 2, swap it with the element at high index
            // Move the high pointer to the left
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
