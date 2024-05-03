class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length; // Get the length of the array
        k = k % n; // Calculate the effective number of rotations
        
        // Reverse the first part of the array (from index 0 to n - k - 1)
        reverse(nums, 0, n - k - 1);
        
        // Reverse the second part of the array (from index n - k to n - 1)
        reverse(nums, n - k, n - 1);
        
        // Reverse the entire array to complete rotation
        reverse(nums, 0, n - 1);
    }
    
    // Method to reverse the elements in the given range of the array
    void reverse(int[] nums, int start, int end) {
        int temp;
        while (start < end) { // Iterate until start index is less than end index
            temp = nums[start]; // Swap elements at start and end indices
            nums[start] = nums[end];
            nums[end] = temp;
            start++; // Move start index forward
            end--; // Move end index backward
        }
    }
}
