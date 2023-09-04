class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int cost=0;
        for(int i=0;i<s.length();i++)
        {
            // Opening Brackt
            if(s[i]=='(')
            st.push(s[i]);
            // Closed Brcket
            else
            {
                // stack if empty
                if(st.empty())
                cost+=1;
                else
                st.pop();
            }
        }
        cost+=st.size();
        return cost;
    }
};