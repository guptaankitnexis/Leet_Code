class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Sort both arrays to facilitate the two-pointer technique
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;  // Vector to store the intersection
        int ptr1 = 0;     // Pointer for nums1
        int ptr2 = 0;     // Pointer for nums2
        int lastAdded = -1;  // To track the last added element and avoid duplicates

        // Traverse both arrays using two pointers
        while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
            if (nums1[ptr1] == nums2[ptr2]) {
                // Add to result if it is not a duplicate
                if (nums1[ptr1] != lastAdded) {
                    ans.push_back(nums1[ptr1]);
                    lastAdded = nums1[ptr1];  // Update the last added element
                }
                ptr1++;
                ptr2++;
            } else if (nums1[ptr1] < nums2[ptr2]) {
                ptr1++;  // Move pointer of nums1 forward
            } else {
                ptr2++;  // Move pointer of nums2 forward
            }
        }

        return ans;  // Return the result containing unique intersections
    }
};