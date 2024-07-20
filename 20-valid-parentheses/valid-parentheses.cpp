class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Stack to keep track of opening brackets
        for(auto it : s) {
            if(it == '(' || it == '{' || it == '[') {
                st.push(it);  // Push opening brackets onto the stack
            } else {
                if(st.size() == 0) return false;  // If stack is empty and closing bracket found, return false
                char ch = st.top();  // Get the top element from the stack
                st.pop();  // Remove the top element from the stack
                // Check if the closing bracket matches the corresponding opening bracket
                if((it == ')' && ch == '(') ||  (it == ']' && ch == '[') || (it == '}' && ch == '{')) {
                    continue;
                } else {
                    return false;  // If not a match, return false
                }
            }
        }
        return st.empty();  // If stack is empty, all brackets matched, return true; otherwise, return false
    }
};