class MyQueue {
public:    
    stack<int> s1;
    stack<int> s2;
    int size;
    MyQueue() {
        size = 0;
    }
    
    void push(int x) {
        for (int i = 0; i < size; i++)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        for (int i = 0; i < size; i++)
        {
            s1.push(s2.top());
            s2.pop();
        }
        size++;
    }
    
    int pop() {
        if (!s1.empty())
        {
            int element=s1.top();
            s1.pop();
            size--;
            return element;
        }
        return -1;
    }
    
    int peek() {
        if (!s1.empty())
        {
            return s1.top();
        }
        return -1;
    }
    
    bool empty() {
        return size==0?true:false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */