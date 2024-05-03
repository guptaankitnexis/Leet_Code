class Solution {
    public void moveZeroes(int[] nums) {
        int j = -1; // Pointer to the first zero element
        int n = nums.length; // Length of the array
        
        // Find the first zero element
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i; // Update the pointer to the index of the first zero
                break;
            }
        }
        
        // If no zero is found, no need to perform any operation
        if (j == -1) {
            return;
        }
        
        // Move non-zero elements to the left of the first zero
        for (int i = j + 1; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums, i, j); // Swap current non-zero element with the first zero
                j++; // Move the pointer to the next position
            }
        }
    }
    
    // Swap elements at given indices in the array
    void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
