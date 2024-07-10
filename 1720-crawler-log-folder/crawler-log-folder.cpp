class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;  // Initialize a counter to keep track of the current directory level
        
        for(int i = 0; i < logs.size(); i++) {  // Iterate through each log entry
            if(logs[i] == "../") {  // If the log is "../"
                if(count > 0) {  // and we're not at the root, go up one level
                    count--;
                }
            } else if(logs[i] != "./") {  // If the log is not "./" (i.e., it is a valid directory change)
                count++;
            }
        }
        
        return count;  // Return the final directory level
    }
};
