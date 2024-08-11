class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int sign = 1;
        int i = 0;
        
        // Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') i++;
        
        // Handle sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Convert digits to integer
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
            
            // Check for overflow
            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return res * sign;
    }
};