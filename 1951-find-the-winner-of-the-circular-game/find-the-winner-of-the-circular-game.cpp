class Solution {
public:
    int findTheWinner(int n, int k) { 
        // Call the solve function with n-1 and k, adjust result for 1-based index
        return solve(n , k) + 1; 
    }

    int solve(int n, int k) {
        if (n == 1) // Base case: if there's only one person, they're the winner
            return 0;
        // Recursive case: calculate position for n-1 people and adjust with k
        return (solve(n - 1, k) + k) % n;
    }
};