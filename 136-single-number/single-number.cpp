class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mpp; // Create a map to store the count of each number
        for(int i = 0 ;i<nums.size();i++){
            mpp[nums[i]]++; // Increment count for each number
        }
        for (auto it : mpp) { // Iterate through the map
            if(it.second == 1 ){ // If count is 1, return the number
                return it.first;
            }
        }
        return -1; // Return -1 if no unique element found
    }
};
