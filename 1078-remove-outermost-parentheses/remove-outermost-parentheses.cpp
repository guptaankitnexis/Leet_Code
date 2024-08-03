class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;  // String to store the result
        int count = 0;  // Counter to track the balance of parentheses
        
        // Iterate through each character in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;  // Increment counter for an opening parenthesis
                if (count > 1) {
                    ans += s[i];  // Add to result if it's not an outermost parenthesis
                }
            } else {
                count--;  // Decrement counter for a closing parenthesis
                if (count > 0) {
                    ans += s[i];  // Add to result if it's not an outermost parenthesis
                }
            }
        }
        
        return ans;  // Return the resulting string
    }
};
