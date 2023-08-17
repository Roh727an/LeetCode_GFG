class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        // 1.Put all Elements from Stack 1 to Stack 2
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // 2.Push into Stack 2
        s2.push(x);
        // 3.Put back all Elements from Stack 2 to Stack 1
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        // Simple Pop from stack 1
        int ele=s1.top();
        s1.pop();
        return ele;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
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