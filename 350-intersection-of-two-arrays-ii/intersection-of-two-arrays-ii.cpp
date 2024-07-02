class Solution {
public:
    vector<int> intersect(vector<int>& array1, vector<int>& array2) {
        // Sort both input arrays
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());

        // Vector to store the intersection result
        vector<int> intersectionResult;

        // Pointers to traverse both arrays
        int pointer1 = 0;
        int pointer2 = 0;

        // Traverse both arrays
        while (pointer1 < array1.size() && pointer2 < array2.size()) {
            // If elements at both pointers are equal, add to the result
            if (array1[pointer1] == array2[pointer2]) {
                intersectionResult.push_back(array1[pointer1]);
                pointer1++;
                pointer2++;
            }
            // Move the pointer of the smaller element
            else if (array1[pointer1] < array2[pointer2]) {
                pointer1++;
            }
            else {
                pointer2++;
            }
        }

        // Return the intersection result
        return intersectionResult;
    }
};