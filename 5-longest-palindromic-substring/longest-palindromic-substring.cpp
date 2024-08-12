class Solution {
public:
    string longestPalindrome(string s) {
        string longestPalin;
        int maxLength = 0;
        int length = s.length();
        
        for(int i = 0; i < length; i++) {
            // odd length palindrome
            int left = i;
            int right = i;
            while(left >= 0 && right < length && s[left] == s[right]) {
                if(right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    longestPalin = s.substr(left, maxLength);
                }
                left--;
                right++;
            }
            // even length palindrome
            left = i;
            right = i + 1;
            while(left >= 0 && right < length && s[left] == s[right]) {
                if(right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    longestPalin = s.substr(left, maxLength);
                }
                left--;
                right++;
            }
        }
        return longestPalin;
    }
};
