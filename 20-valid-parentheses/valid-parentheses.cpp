class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
            st.push(s[i]);
            else
            {
                if(st.empty())
                return false;
                char op=st.top();
                if((op=='(' && s[i]!=')')||(op=='{' && s[i]!='}') || (op=='[' && s[i]!=']'))
                return false;
                else
                st.pop();    
            }
        }
        return st.empty();
    }
};