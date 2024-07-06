class Solution {
public:
    int passThePillow(int n, int time) {
        // Calculate the number of complete rounds the pillow has passed
        int round = time / (n-1);
        
        // Calculate the remaining time after complete rounds
        time = time % (n-1);
        
        // If the number of rounds is even, the pillow is at the 1st position and moves from 1st position to nth position
        if (round % 2 == 0) {
            return time + 1; // Position of the pillow is simply the remaining time + 1
        } 
        // If the number of rounds is odd, the pillow is at the nth position and moves from nth position to 1st position
        else {
            return (n - time); // Position of the pillow is the total people minus the remaining time
        }
    }
};
