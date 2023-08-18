class MinStack {
public:
    stack<long long>st;
    long long mini=INT_MAX;;
    MinStack() {
        
    }
    
    void push(int val) {
        // 1.If val is less than Mini then we Push Modified Value into Stack
        if(val  <mini){
            long long mod_val= (long long)2*val  - mini;
            mini=val;
            st.push(mod_val);
        }
        // Else we do a Simple Push
        else
        {
            st.push(val);
        }
    }
    
    void pop() {
        // If the Popped Value is Modified Value then we have to Update Mini
        if(st.top() < mini)
        {
            mini=2*mini-st.top();
            st.pop();
        }
        // Else we Simply Pop from Stack
        else
        st.pop();
    }
    
    int top() {
        // If Stack top Contains Modified Value then we Retrun Mini
        if(st.top() < mini)
        {
            return (int)mini;
        }
        // Else we Return Stack Top
        else
        return (int)st.top();
    }
    
    int getMin() {
        // We Simply Return our Mini which contains minimum Value present in the Stack
        return (int)mini;
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