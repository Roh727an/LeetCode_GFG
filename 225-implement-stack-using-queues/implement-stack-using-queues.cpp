class MyStack {
public:
    queue<int>q;
    queue<int>q_ref;
    MyStack() {

    }
    
    void push(int x) {
        // 1.Put Elements From Main Queue(MyStack) to Reference Queue
        while(!q.empty())
        {
            q_ref.push(q.front());
            q.pop();
        }
        // 2.Push Element(X) in Main Queue(MyStack)
        q.push(x);
        // 3.Put Back all Elements From Reference Queue to Main Queue(MyStack)
        while(!q_ref.empty())
        {
            q.push(q_ref.front());
            q_ref.pop();
        }
    }
    
    int pop() {
        // Simply pop from Main Queue
        int ele=top();
        q.pop();
        return ele;
        
    }
    
    int top() {
        // Simply Return Main Queue front
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