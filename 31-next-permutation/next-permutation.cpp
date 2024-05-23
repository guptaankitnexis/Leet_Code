class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // Find the first decreasing element from the right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // If no such element is found, reverse the whole array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            // Find the element just larger than nums[index] from the right
            for (int i = n - 1; i > index; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums[i], nums[index]);
                    break;
                }
            }
            // Reverse the elements from index + 1 to the end to get the next permutation
            reverse(nums.begin() + index + 1, nums.end());
        }
    }
};
