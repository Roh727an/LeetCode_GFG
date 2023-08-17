    class MinStack {
public:
    stack<int>st;
    stack<int>ref_st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        // 1.Put all Elements from Stack 1 to Reference Stack
        int minEle=INT_MAX;
        while(!st.empty())
        {
            ref_st.push(st.top());
            if(minEle > st.top())
            {
                minEle=st.top();
            }
            st.pop();
        }
        // 2.Put Back all Elements from Reference Stack to Main Stack.
        while(!ref_st.empty())
        {
            st.push(ref_st.top());
            ref_st.pop();
        }
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */