class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        map<char, int> mpp;

        // Count frequency of each character in string s
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }

        // Decrement frequency for each character in string t
        for (int i = 0; i < t.size(); i++) {
            if (mpp[t[i]] == 0) return false; // If character in t is not found or exceeds the count in s
            mpp[t[i]]--;
        }

        return true;
    }
};