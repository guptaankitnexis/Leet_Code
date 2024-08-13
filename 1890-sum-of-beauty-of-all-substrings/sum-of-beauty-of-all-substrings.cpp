#include <map>
#include <climits>
#include <string>
#include <algorithm>

class Solution {
public:
    int beautySum(std::string s) {
        int n = s.size();
        int totalBeautySum = 0;

        // Iterate over all possible starting points of substrings
        for (int start = 0; start < n; start++) {
            map<char, int> frequencyMap;

            // Iterate over all possible ending points of substrings
            for (int end = start; end < n; end++) {
                // Increment the frequency of the current character
                frequencyMap[s[end]]++;

                // Initialize maxi and mini to extremes
                int maxFrequency = INT_MIN;
                int minFrequency = INT_MAX;

                // Find the maximum and minimum frequency of characters in the current substring
                for (const auto& entry : frequencyMap) {
                    maxFrequency = std::max(maxFrequency, entry.second);
                    minFrequency = std::min(minFrequency, entry.second);
                }

                // Add the difference to the total beauty sum
                totalBeautySum += maxFrequency - minFrequency;
            }
        }
        return totalBeautySum;
    }
};
