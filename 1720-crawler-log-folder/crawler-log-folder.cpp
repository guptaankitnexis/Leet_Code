class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;  // Initialize a counter to keep track of the current directory level
        
        for(int i = 0; i < logs.size(); i++) {  // Iterate through each log entry
            if(logs[i] == "../" && count > 0) {  // If the log is "../" and we're not at the root, go up one level
                count--;
            } else if(logs[i] != "./" && logs[i] != "../") {  // If the log is not "./" and not "../" (i.e., it is a valid directory change)
                count++;
            }
        }
        
        return count;  // Return the final directory level
    }
};