class Solution {
public:
    // Helper function to remove pairs using string operations
    void removePairs(string &s, const string &pair, int points, int &score) {
        string result; // To simulate stack behavior
        for (char c : s) {
            // Check if the last character in result forms the pair with c
            if (!result.empty() && result.back() == pair[0] && c == pair[1]) {
                result.pop_back(); // Remove the last character from result
                score += points;   // Add points to the score
            } else {
                result.push_back(c); // Push the current character onto result
            }
        }
        // Update the original string with the modified result
        s = result;
    }

    int maximumGain(string s, int x, int y) {
        int score = 0; // Initialize score
        string firstPair, secondPair; // To store the pairs to be removed
        int firstScore, secondScore;  // To store the points for each pair

        // Determine the order of removal based on x and y
        if (x >= y) {
            firstPair = "ab";
            firstScore = x;
            secondPair = "ba";
            secondScore = y;
        } else {
            firstPair = "ba";
            firstScore = y;
            secondPair = "ab";
            secondScore = x;
        }

        // First remove pairs based on the priority
        removePairs(s, firstPair, firstScore, score);
        // Then remove the other pairs
        removePairs(s, secondPair, secondScore, score);

        return score; // Return the total score
    }
};