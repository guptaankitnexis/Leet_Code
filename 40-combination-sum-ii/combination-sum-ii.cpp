class Solution {
public:
    void findCombinations(int index, int target, vector<int> &candidates, vector<int> &currentCombination, vector<vector<int>> &result) {
        // Base case: if target is reached, add the current combination to the result
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            // If the candidate is greater than the remaining target, stop the loop
            if (candidates[i] > target) break;
            
            // Include the candidate and move to the next element
            currentCombination.push_back(candidates[i]);
            findCombinations(i + 1, target - candidates[i], candidates, currentCombination, result);
            // Backtrack: remove the last added candidate
            currentCombination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;  // To store the result combinations
        vector<int> currentCombination;  // To store the current combination
        sort(candidates.begin(), candidates.end());  // Sort candidates to handle duplicates and make it easier to manage
        findCombinations(0, target, candidates, currentCombination, result);
        return result;
    }
};
