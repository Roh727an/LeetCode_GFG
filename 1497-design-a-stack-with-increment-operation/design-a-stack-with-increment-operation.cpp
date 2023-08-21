class CustomStack {
public:
    vector<int>st;
    int n;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        // Not Full
        if(st.size()<n)
        st.push_back(x);
    }
    
    int pop() {
        // if Non-Empty
        if(st.size()!=0)
        {
            int top_Ele=st[st.size()-1];
            st.pop_back();
            return top_Ele;
        }
        // Empty
        return -1;

    }
    
    void increment(int k, int val) {
        // First Elements of Array = Bottom Elements of Stack (VVVVVVI)
        // Calculate Range
        int range;
        if(k<=st.size())
        range=k;
        else
        range=st.size();
        // Update First Range Elements from Array to Update Bottom of Stack
        for(int i=0;i<range;i++)
        st[i]+=val;

        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */