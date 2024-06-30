class Solution {
public:
    // Function to get all possible letter combinations for a given digit string
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        
        // Return empty result if input is empty
        if (digits == "") {
            return combinations;
        }
        
        // Mapping of digits to corresponding letters
        string digitToLetters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // Start the recursive process
        generateCombinations("", 0, combinations, digits, digitToLetters);
        
        return combinations;
    }

private:
    // Helper function to generate combinations recursively
    void generateCombinations(string currentCombination, int index, vector<string>& combinations, string digits, string digitToLetters[]) {
        // Base case: if current index equals the length of the digits, add the current combination to the result
        if (index == digits.length()) {
            combinations.push_back(currentCombination);
            return;
        }
        
        // Get the number corresponding to the current digit
        int num = digits[index] - '0';
        string letters = digitToLetters[num];
        
        // Iterate through each letter corresponding to the current digit and recursively generate combinations
        for (int i = 0; i < letters.length(); i++) {
            currentCombination.push_back(letters[i]);
            generateCombinations(currentCombination, index + 1, combinations, digits, digitToLetters);
            currentCombination.pop_back(); // backtrack to explore other combinations
        }
    }
};