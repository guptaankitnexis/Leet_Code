class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Maps to store the character mappings from s to t and t to s
        unordered_map<char, char> mpp;
        unordered_map<char, char> spp;

        // Loop through each character in the strings
        for (int i = 0; i < s.size(); i++) {
            // Check if the current character in s is already mapped to a different character in t
            // Or if the current character in t is already mapped to a different character in s
            if ((mpp.find(s[i]) != mpp.end() && mpp[s[i]] != t[i]) || 
                (spp.find(t[i]) != spp.end() && spp[t[i]] != s[i])) {
                return false;  // Return false if any mismatch is found
            }

            // Map the characters from s to t and t to s
            mpp[s[i]] = t[i];
            spp[t[i]] = s[i];
        }
        return true;  // Return true if no mismatches are found
    }
};
