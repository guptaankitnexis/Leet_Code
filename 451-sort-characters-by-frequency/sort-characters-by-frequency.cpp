class Solution {
public:
    // Comparator to sort by frequency in descending order
    static bool compareByFrequency(pair<char, int>& a, pair<char, int>& b) {
        return b.second < a.second; // Larger frequency first
    }

    string frequencySort(string input) {
        unordered_map<char, int> charFrequencyMap;
        
        // Count frequency of each character
        for (char ch : input) {
            charFrequencyMap[ch]++;
        }

        // Convert the map to a vector of pairs
        vector<pair<char, int>> frequencyVector(charFrequencyMap.begin(), charFrequencyMap.end());

        // Sort the vector by frequency in descending order
        sort(frequencyVector.begin(), frequencyVector.end(), compareByFrequency);

        string sortedResult;
        
        // Construct the result string based on frequency
        for (auto& entry : frequencyVector) {
            sortedResult.append(entry.second, entry.first);
        }

        return sortedResult;
    }
};