class Solution {
public:
    vector<int> generateRow(int row){
        vector<int> tempList; // Initialize a temporary list to store the current row
        tempList.push_back(1); // The first element of every row is always 1
        int ans = 1; // Initialize ans to 1 for the first element
        for(int i = 1; i < row; i++){
            ans *= (row - i); // Calculate the next element in the row
            ans /= i; // Continue the calculation for the next element
            tempList.push_back(ans); // Add the calculated element to the row
        }
        return tempList; // Return the completed row
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ansList; // Initialize the list to store all rows
        for(int i = 1; i <= numRows; i++){
            ansList.push_back(generateRow(i)); // Generate and add each row to the list
        }
        return ansList; // Return the list containing all rows
    }
};