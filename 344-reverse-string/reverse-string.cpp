class Solution {
public:
    void reverseString(vector<char>& s) {
    stack<char>st;
    // Push Element from String to Stack
    for(int i=0;i<s.size();i++)
    {
        st.push(s[i]);
    }
    int i=0;
    // Put Back elements Form Stack to String
    while(!st.empty())
    {
        s[i++]=st.top();
        st.pop();
    }
    }
};