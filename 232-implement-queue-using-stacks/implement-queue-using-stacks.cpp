class MyQueue {
public:
    stack<int>st;
    stack<int>refSt; 
    MyQueue() {

    }
    
    void push(int x) {
        // cout<<"Push "<<x<<endl;
        // Move all Elements from s1 to s2
        while(!st.empty())
        {
        refSt.push(st.top());
        st.pop();
        }
        // Push into s1
        st.push(x);
        // Move all Elements from s2 to s1
        while(!refSt.empty())
        {
        st.push(refSt.top());
        refSt.pop();
        }
        // cout<<"Top of s1 is "<<st.top()<<endl;
    }
    
    int pop() {
        int val=st.top();
        st.pop();
        // cout<<"Pop "<<val<<endl;
        return val;
    }
    
    int peek() {
        // cout<<"peak "<<st.top()<<endl;
        if(st.empty())
        return -1;
        return st.top();
    }
    
    bool empty() {
        // cout<<"empty "<<st.empty()<<endl;
        return st.empty();
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