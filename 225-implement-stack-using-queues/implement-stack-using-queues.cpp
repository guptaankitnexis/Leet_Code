class MyStack {
public:
    queue<int> q;
    int size;
    MyStack() { size = 0; }

    void push(int x) {
        int currentSize = size;
        q.push(x);
        for (int i = 0; i < currentSize; i++) {
            q.push(q.front());
            q.pop();
        }
        size++;
    }

    int pop() {
        if(size!=0){
        int element = q.front();
        q.pop();
        size--;
        return element;
        }
        else{
            return -1;
        }
    }

    int top() {
        if(size!=0){ 
        return q.front();
        }
        else{
            return -1;
        }
    }

    bool empty() {
        return size==0?true:false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */