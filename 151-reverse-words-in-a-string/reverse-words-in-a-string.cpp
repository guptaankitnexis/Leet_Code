class Solution {
public:
    string reverseWords(string s) {
        string temp;
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else if (temp.size() != 0) {
                if (!res.empty()) {
                    res = ' ' + res;
                }
                res = temp + res;
                temp.clear();
            }
        }
        if (temp.size() != 0) {
            if (!res.empty()) {
                res = ' ' + res;
            }
            res = temp + res;
            temp.clear();
        }
        return res;
    }
};