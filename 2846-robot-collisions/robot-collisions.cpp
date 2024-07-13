class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // Mapping positions with indexes
        map<int, int> mpp;
        for (int i = 0; i < positions.size(); i++) {
            mpp[positions[i]] = i;
        }

        // Sorting the positions array to make robots stand on a lane
        sort(positions.begin(), positions.end());

        // Stack for storing indexes of robots moving in the 'R' direction
        stack<int> st;
        
        // Traversing through robots' positions
        for (int i = 0; i < positions.size(); i++) {
            int key = positions[i];
            int index = mpp[key];
            if (directions[index] == 'R') {
                // Push index of robots moving right into the stack
                st.push(index);
            } else if (directions[index] == 'L') {
                // Handle collisions for robots moving left
                while (!st.empty() && directions[st.top()] == 'R' && healths[index] != 0) {
                    if (healths[st.top()] > healths[index]) {
                        // Current left-moving robot is destroyed
                        healths[index] = 0;
                        // Right-moving robot's health is reduced by 1
                        healths[st.top()] -= 1;
                    } else if (healths[st.top()] < healths[index]) {
                        // Right-moving robot is destroyed
                        healths[index] -= 1;
                        healths[st.top()] = 0;
                        st.pop();
                    } else {
                        // Both robots destroy each other
                        healths[index] = 0;
                        healths[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        }

        // Saving the health of all remaining robots
        vector<int> ans;
        for (int i = 0; i < healths.size(); i++) {
            if (healths[i] != 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};