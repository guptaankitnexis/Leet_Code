class Solution {
public:
    bool rotateString(string s, string goal) {
        // If the lengths of s and goal are not the same, return false
        if(s.size() != goal.size()) return false;
        
        // Concatenate s with itself to form a doubled string
        string doubled_s = s + s;
        
        // Check if goal is a substring of the doubled string
        // If it is, return true; otherwise, return false
        return doubled_s.find(goal) != string::npos;
    }
};
