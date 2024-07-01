class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0; // Initialize a counter to track consecutive odd numbers
        for(int i = 0; i < arr.size(); i++) { // Iterate through the array
            if(arr[i] % 2 == 1) { // Check if the current element is odd
                count++; // Increment the counter if it is odd
                if(count == 3) { // Check if there are three consecutive odds
                    return true; // Return true if there are three consecutive odd numbers
                }
            } else {
                count = 0; // Reset the counter if the current element is not odd
            }
        }
        return false; // Return false if there are no three consecutive odd numbers
    }
};
