class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Take the first string as the initial common prefix
        string prefix = strs[0];
        
        // Iterate over the rest of the strings
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            // Compare the characters of the current string with the prefix
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                j++;
            }
            // Update the prefix to the common part
            prefix = prefix.substr(0, j);
            if (prefix.empty()) return "";
        }
        
        return prefix;
    }
};
