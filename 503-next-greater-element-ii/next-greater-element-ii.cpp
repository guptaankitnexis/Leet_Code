class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size());
        int n = nums.size();
        for(int i =0;i<n;i++){
            bool flag = true;
            for(int j = i+1;j<i+n;j++){
                int k = j%n;
                if(nums[k]>nums[i]){
                    ans[i]=nums[k];
                    flag= false;
                    break;
                }
            }
            if(flag){
                ans[i]=-1;
            }
        }
        return ans;
    }
};