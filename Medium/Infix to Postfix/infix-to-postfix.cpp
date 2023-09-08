//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int prec(char ch)
  {
    if(ch=='^') return 3;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return -1;

  }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        // 1.Create a Stack
        stack<char>st;
        string postfix="";
        // 2.Iterate Over Given String/Infix Expression
        for(int i=0;i<s.length();i++)
        {
            // a.Operands
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
            postfix+=s[i];

            // b.Opening Bracket
            else if(s[i]=='(')
            st.push(s[i]);

            // c.Closing Bracket
            else if(s[i]==')')
            {
                // Pop till Opening Bracket comes out 
                while(!st.empty() && st.top()!='(')
                {
                    postfix+=st.top();
                    st.pop();
                }
                // pop the Opening Bracket
                if(!st.empty())
                st.pop();
            }
            // Operator
            else
            {
                // pop element till Precedence of Current Element is Smaller Than Stack top
                while(!st.empty() && prec(st.top()) >= prec(s[i]))
                {
                    postfix+=st.top();
                    st.pop();
                }
                // Push the Current Element
                st.push(s[i]);
            }
        }
        // Add Remaining Elements
        while(!st.empty())
        {
            postfix+=st.top();
            st.pop();
        }
        return postfix;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends