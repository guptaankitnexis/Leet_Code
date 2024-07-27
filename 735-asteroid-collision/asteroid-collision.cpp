class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // stack to store the state of asteroids
        int n = asteroids.size(); // number of asteroids
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                // if asteroid is moving to the right, push it onto the stack
                st.push_back(asteroids[i]);
            } 
            else {
                // if asteroid is moving to the left
                while (!st.empty() && st.back() > 0 &&
                       st.back() < abs(asteroids[i])) {
                    // pop all smaller right-moving asteroids
                    st.pop_back();
                }
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    // if top of stack is the same size but opposite direction, both explode
                    st.pop_back();
                } 
                else if (st.empty() || st.back() < 0) {
                    // if stack is empty or top of stack is also moving left, push current asteroid
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st; // return the remaining asteroids
    }
};