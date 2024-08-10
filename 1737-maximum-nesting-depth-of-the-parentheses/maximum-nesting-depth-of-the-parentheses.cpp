class Solution {
public:
    int maxDepth(string s) {
        int count = 0;          // Tracks the current depth of nested parentheses
        int maxDepth = 0;       // Tracks the maximum depth encountered
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {   // If an opening parenthesis is found
                count++;        // Increase the current depth
                maxDepth = max(maxDepth, count);  // Update maxDepth if current depth is greater
            } else if(s[i] == ')') {  // If a closing parenthesis is found
                count--;        // Decrease the current depth
            }
        }
        return maxDepth;        // Return the maximum depth encountered
    }
};
