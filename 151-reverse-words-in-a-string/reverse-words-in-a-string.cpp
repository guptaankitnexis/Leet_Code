class Solution {
public:
    string reverseWords(string s) {
        string temp;
        vector<string> arr;
        
        for (char c : s) {
            if (c != ' ') {
                temp += c;
            } else if (!temp.empty()) { 
                arr.push_back(temp);
                temp.clear();
            }
        }
        
        if (!temp.empty()) { 
            arr.push_back(temp);
        }
        
        string result;
        for (int i = arr.size() - 1; i >= 0; --i) {
            result += arr[i];
            if (i > 0) {
                result += ' ';
            }
        }
        
        return result;
    }
};