class Solution {
public:
    bool isPalindrome(int x) {
        // Convert integer x to a string representation
        std::string num = std::to_string(x);
        
        // Initialize two pointers: left starts from the beginning, right starts from the end
        int left = 0;
        int right = num.size() - 1;
        
        // Continue checking characters until left pointer is less than right pointer
        while (left < right) {
            // If characters at left and right pointers are not equal, it's not a palindrome
            if (num[left] != num[right]) {
                return false;
            }
            // Move to the next pair of characters
            left++;
            right--;
        }
        
        // If all pairs match, it's a palindrome
        return true;
    }
};