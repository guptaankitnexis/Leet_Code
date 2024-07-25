class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        int leftMax = height[0];
        // suffix Maximum
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        for (int i = 1; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            if (height[i] < leftMax && height[i] < rightMax[i]) {
                totalWater += min(leftMax, rightMax[i]) - height[i];
            }
        }
        return totalWater;
    }
};