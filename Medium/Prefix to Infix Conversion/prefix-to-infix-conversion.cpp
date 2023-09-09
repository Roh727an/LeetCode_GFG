//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends