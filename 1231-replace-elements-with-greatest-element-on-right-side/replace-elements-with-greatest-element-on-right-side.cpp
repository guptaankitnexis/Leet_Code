class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans; // Result vector
        int n = arr.size(); // Size of the input array
        int maxi = -1; // Initialize maximum to -1
        
        // Traverse the array from end to start
        for(int i = n-1; i >= 0; i--) {
            ans.push_back(maxi); // Add current maximum to result
            if(arr[i] > maxi) {
                maxi = arr[i]; // Update maximum if current element is larger
            }
        }
        
        reverse(ans.begin(), ans.end()); // Reverse the result vector
        return ans; // Return the final result
    }
};
