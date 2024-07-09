class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime = customers[0][0];  // Initialize current time to the arrival time of the first customer
        double totalWaitingTime = 0;           // Accumulate total waiting time
        int totalCustomers = customers.size();  // Total number of customers

        for (int i = 0; i < totalCustomers; i++) {
            int arrivalTime = customers[i][0];  // Customer's arrival time
            int serviceDuration = customers[i][1];  // Time to serve the customer

            if (currentTime - arrivalTime <= 0) {
                // If the server is idle, waiting time is just the service duration
                totalWaitingTime += serviceDuration;
            } else {
                // If the server is busy, waiting time includes the time spent waiting
                totalWaitingTime += currentTime - arrivalTime + serviceDuration;
            }

            // Update current time to when the customer is fully served
            currentTime = max(currentTime, arrivalTime) + serviceDuration;

        }

        // Calculate average waiting time
        double averageWaitingTime = totalWaitingTime / totalCustomers;
        return averageWaitingTime;
    }
};