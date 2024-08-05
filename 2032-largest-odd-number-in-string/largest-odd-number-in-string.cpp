class Solution {
public:
    string largestOddNumber(string num) {
        // Traverse the string from the end to the beginning
        for(int i = num.size() - 1; i >= 0; i--) {
            // Convert the character to its corresponding integer digit and check if it is odd
            if((num[i] - '0') % 2 == 1) {
                // Return the substring from the beginning to the current position (inclusive)
                return num.substr(0, i + 1);
            }
        }
        // If no odd number is found, return an empty string
        return "";
    }
};