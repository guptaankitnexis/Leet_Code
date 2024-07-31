class StockSpanner {
public:
    int i; // Index to keep track of the current day
    stack<int> st; // Stack to store indices of the days
    vector<int> arr; // Vector to store the prices

    StockSpanner() { 
        i = 0; // Initialize the index to 0
    }

    int next(int price) { 
        arr.push_back(price); // Add the current day's price to the vector
        // While stack is not empty and the price at the top index of the stack is less than or equal to the current price
        while (!st.empty() && arr[st.top()] <= arr[i]){
            st.pop(); // Pop the top index from the stack
        } 
        // Calculate the span: if the stack is empty, the span is i+1, otherwise, it's the difference between the current index and the index at the top of the stack
        int ans = st.empty() ? i + 1 : i - st.top();
        st.push(i); // Push the current index onto the stack
        i++; // Move to the next day
        return ans; // Return the span
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
