class MinStack {
  // Stack to store pairs of (value, current minimum)
  stack<pair<int, int>> st;

public:
  // Push a new value onto the stack
  void push(int x) {
    int min;
    // If the stack is empty, the minimum is the new value
    if (st.empty()) {
      min = x;
    } else {
      // Otherwise, the minimum is the lesser of the current minimum and the new value
      min = std::min(st.top().second, x);
    }
    // Push the new value and the current minimum onto the stack
    st.push({x, min});
  }

  // Pop the top value from the stack
  void pop() {
    st.pop();
  }

  // Get the top value from the stack without removing it
  int top() {
    return st.top().first;
  }

  // Get the current minimum value from the stack
  int getMin() {
    return st.top().second;
  }
};