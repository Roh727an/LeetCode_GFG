//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      int prec(char ch)
  {
    if(ch=='^') return 3;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return -1;

  }
  string preToInfix(string pre_exp) {
        // Write your code here
        // 1.Create a Stack
        stack<string>st;
        // 2.Scan the Prefix Expression from Right to Left
        for(int i=pre_exp.length()-1;i>=0;i--)
        {
            // a.If operand comes then push into stack
            if((pre_exp[i]>='a' && pre_exp[i]<='z')|| (pre_exp[i]>='A' && pre_exp[i]<='Z') || (pre_exp[i]>='0' && pre_exp[i]<='9'))
            {
                string temp="";
                temp+=pre_exp[i];
                st.push(temp);
            }
            // b.if operator comes then -
            else
            {
                // i.pop the first 2 operand
                string op1="";
                op1+=st.top();
                st.pop();
                string op2="";
                op2+=st.top();
                st.pop();
                // ii. Create newExpression as ")" + op2 + operator + op1 +"(" & push into stack
                string newExp=")" + op2 + pre_exp[i] + op1 +"(";
                st.push(newExp);
            }
        }
        // 3.After scan stack topcontains Reverse Infix Expression
        string infix=st.top();
        // 4.Reverse the Expression to get Correct Infix Expression
        reverse(infix.begin(),infix.end());
        return infix;
    }
    string infixToPostfix(string s) {
        // Your code here
        // 1.Create a Stack
        stack<char>st;
        string postfix="";
        // 2.Iterate Over Given String/Infix Expression
        for(int i=0;i<s.length();i++)
        {
            // a.Operands
            if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9')
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
    string preToPost(string pre_exp) {
        // 1.Convert Prefix to Infix
        string infix=preToInfix(pre_exp);
        // 2.Convert Infx to Postfix
        string postfix=infixToPostfix(infix);
        return postfix;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends