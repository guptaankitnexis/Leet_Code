class StockSpanner {
public:
    int i; // Index to keep track of the current day
    stack<pair<int, int>> st; // Stack to store pairs of (price, index)

    StockSpanner() {
        i = 0; // Initialize the index to 0
    }

    int next(int price) {
        // While stack is not empty and the price at the top of the stack is less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            st.pop(); // Pop the top element from the stack
        }
        // Calculate the span: if the stack is empty, the span is i+1, otherwise, it's the difference between the current index and the index of the top element in the stack
        int ans = st.empty() ? i + 1 : i - st.top().second;
        st.push({price, i}); // Push the current price and index onto the stack
        i++; // Move to the next day
        return ans; // Return the span
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
