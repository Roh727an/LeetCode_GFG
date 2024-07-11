class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string ans = "";
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            // Opening Bracket (index)
            if(s[i] == '(')
                st.push(i);
            // Closing Bracket 
            else if(s[i] == ')')
            {
            // Get the Opening Bracket index
                int start = st.top()+1;
                // Get the Closing Bracket Index
                int end = i;

                // Reverse from OpeningBr+1 to ClosingBr-1 (into Original String)
                reverse(s.begin()+start, s.begin()+end);
                // Pop the Opening Bracked index from Stack
                st.pop();
            }
        }

        for(auto &ch : s)
        {
            if(ch != '(' && ch != ')')
                ans += ch;
        }

        return ans;
    }
};