class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int lenNums1 = nums1.size();  // Length of nums1
        vector<int> result(lenNums1); // Resultant vector to store answers
        stack<int> stk;               // Stack to keep track of elements
        map<int, int> nextGreaterMap; // Map to store next greater element for each number

        // Traverse nums2 from right to left
        for(int i = nums2.size() - 1; i >= 0; i--) {
            // Maintain elements in stack in decreasing order
            while(!stk.empty() && stk.top() <= nums2[i]) {
                stk.pop();
            }

            // If stack is empty, there is no greater element
            if(stk.empty()) {
                nextGreaterMap[nums2[i]] = -1;
            } else {
                nextGreaterMap[nums2[i]] = stk.top(); // Top element is the next greater
            }

            // Push current element to stack
            stk.push(nums2[i]);
        }

        // Fill result array using the map
        for(int i = 0; i < lenNums1; i++) {
            result[i] = nextGreaterMap[nums1[i]];
        }

        return result; // Return the result vector
    }
};