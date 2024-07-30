class Solution {
public:
    string removeKdigits(string num, int k) {
        string st; // Initialize a stack to store the digits
        for (int i = 0; i < num.size(); i++) {
            // Remove elements from the stack if the current element is smaller
            // and we still have k digits to remove
            while (!st.empty() && k > 0 && num[i] < st.back()) {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]); // Push the current digit onto the stack
        }
        
        // If we still have k digits to remove, pop from the stack
        while (k > 0) {
            st.pop_back();
            k--;
        }
        
        // Construct the result string from the stack
        string res;
        for (char c : st) {
            if (res.empty() && c == '0') continue; // Skip leading zeros
            res.push_back(c);
        }
        
        // If the result is empty, return "0"
        return res.empty() ? "0" : res;
    }
};
