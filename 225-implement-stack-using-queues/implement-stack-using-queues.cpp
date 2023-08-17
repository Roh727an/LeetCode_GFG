class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        // 1.Push the element in the queue.
    q.push(x);
    int n=q.size()-1;
    // 2.remove element from queue and again push back to the queue
    while(n--)
    {
        q.push(q.front());
        q.pop();
    }    
    }
    
    int pop() {
        int ele=q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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