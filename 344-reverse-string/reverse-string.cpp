class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;  // Initialize left pointer
        int right = s.size() - 1;  // Initialize right pointer
        
        // Loop until the two pointers meet
        while(left < right){
            // Swap characters at left and right pointers
            swap(s[left], s[right]);
            left++;  // Move left pointer to the right
            right--;  // Move right pointer to the left
        }
    }
};