class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(0, s, path, res);  // Renamed to backtrack
        return res;
    }

    // Helper function for backtracking
    void backtrack(int index, string s, vector<string> &path, vector<vector<string>> &res) {
        // If we've reached the end of the string, add the current partition to the result
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        // Explore all possible partitions
        for (int i = index; i < s.size(); i++) {
            // Check if the substring s[index:i] is a palindrome
            if (isPalindrome(s, index, i)) {
                // If it is, add it to the current path
                path.push_back(s.substr(index, i - index + 1));
                // Recur to partition the remaining substring
                backtrack(i + 1, s, path, res);  // Corrected to func(i + 1, s, path, res)
                // Backtrack by removing the last added substring
                path.pop_back();
            }
        }
    }

    // Function to check if a substring is a palindrome
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};