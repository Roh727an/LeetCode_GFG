class Solution {
public:
    bool isValid(string s) {
        // 1.Create a Stack 
        stack<char>st;
        
        for(int i=0;i<s.length();i++)
        {
            // IF it is an Opening Bracket
            // Push the Opening Bracket into The Stack
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);

            // If it is Closing Bracket then check it's Order into the Stack
            else
            {
                // If there is a Closing Bracket come Before opening one Return false
            if(st.empty())
            return false;
            if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='['))
                st.pop();
                else
                return false;
            }
        }
        return st.empty();
    }
};