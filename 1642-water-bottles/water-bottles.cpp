class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles; // Total number of bottles drunk initially equals the number of full bottles
        int newBottles = 0;
        int leftEmptyBottles = 0;
        
        // Loop until no more full bottles can be obtained
        while (numBottles > 0) {
            // Calculate new full bottles from empty bottles
            newBottles = (numBottles + leftEmptyBottles) / numExchange;
            // Calculate remaining empty bottles after exchange
            leftEmptyBottles = (numBottles + leftEmptyBottles) % numExchange;
            // Add new bottles to the total count
            totalDrunk += newBottles;
            // Update numBottles to the new full bottles obtained
            numBottles = newBottles;
            // Break if no new full bottles can be obtained
            if (newBottles == 0) break;
        }
        return totalDrunk; // Return total number of bottles drunk
    }
};
