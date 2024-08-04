class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;

        // Step 2: Reverse each word in the reversed string
        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ')
                i++;

            // If we've reached the end of the string, break the loop
            if (i == n)
                break;

            // Mark the start of the word
            left = right;

            // Copy the current word to the right position
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // Reverse the current word
            reverse(s.begin() + left, s.begin() + right);

            // Add a space after the word
            s[right++] = ' ';
        }

        // Remove the trailing space if it exists
        s.resize(right - 1);

        return s;
    }
};