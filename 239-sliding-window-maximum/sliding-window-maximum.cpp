class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            // Remove elements smaller than the current element
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            // Add current element's index to the deque
            dq.push_back(i);
            // If the first window is complete, add the maximum to the answer
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};