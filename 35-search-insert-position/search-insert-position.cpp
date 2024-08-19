class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;                           // Start of the search range
        int right = nums.size() - 1;            // End of the search range
        int position = nums.size();             // Default position if target is greater than all elements

        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the middle index

            if (nums[mid] >= target) {           // If target is less than or equal to the middle element
                position = mid;                  // Update potential insert position
                right = mid - 1;                 // Narrow search to the left half
            } else {
                left = mid + 1;                  // Narrow search to the right half
            }
        }
        return position;                         // Return the insert position
    }
};