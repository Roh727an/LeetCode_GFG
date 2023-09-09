//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        // 1.Create a Stack
        stack<string>st;
        // 2.Scan the PostFix Expression From Left to Right-
        for(int i=0;i<exp.length();i++)
        {
            // 3.If the incoming symbol is an Operand then push it into Stack
            if((exp[i]>='a' && exp[i]<='z')|| (exp[i]>='A' && exp[i]<='Z') || (exp[i]>='0' && exp[i]<='9'))
            {
                string op="";
                op+=exp[i];
                st.push(op);
            }
            
            // 4.If the incoming symbol is an Operator then-
            else
            {
                // a.Pop first Two Operands from Stack
                string op1=st.top();
                st.pop();
                string op2=st.top();
                st.pop();
                // b.create a new Expression as "(" + op2 + operator + op1 + ")" & Push it into Stack
                st.push("(" + op2 + exp[i] + op1 + ")");
            }
        }
        // 5.After Scanned the Stack top contains Infix Expression
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends