class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;

        // Prepare the initial list of numbers and calculate (n-1)!
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n); // Add the nth number to the list

        string ans = "";
        k = k - 1; // Adjust k to be zero-indexed

        // Generate the k-th permutation
        while (true) {
            // Select the element at the k/fact position and append to result
            ans += to_string(nums[k / fact]);
            nums.erase(nums.begin() + (k / fact)); // Remove the used element

            // If all elements are used, break
            if (nums.size() == 0) break;

            // Update k and fact for the next iteration
            k %= fact;
            fact /= nums.size();
        }

        return ans; // Return the k-th permutation
    }
};