class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
    if (n == 0) return 0;

    int longest = 1;
    std::unordered_set<int> st;
    // Put all the array elements into the set:
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }

    // Find the longest sequence:
    for (auto it : st) {
        // If 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            // Find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = std::max(longest, cnt);
        }
    }
    return longest;
}
};