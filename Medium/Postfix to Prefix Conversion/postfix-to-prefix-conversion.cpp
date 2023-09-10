//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
            // 1.Create a Stack
        stack<string>st;
        // 2.Scan the Postfix Expression from Left to Right
        for(int i=0;i<post_exp.length();i++)
        {
            // a.If Operand Comes then Push into Stack
            if(post_exp[i]>='a' && post_exp[i]<='z' || post_exp[i]>='A' && post_exp[i]<='Z' || post_exp[i]>='0' && post_exp[i]<='9')
            {
                string temp="";
                temp+=post_exp[i];
                st.push(temp);
            }
            // b.If Operator Comes then -
            else
            {
                // i.Take out first two Operand drom stack 
                string op1=st.top();
                st.pop();
                string op2=st.top();
                st.pop();
                // ii.Create a newExpression as op1+op2+op & push into Stack
                st.push(op1+op2+post_exp[i]);
            }
        }
        // 3.AfterScan ,Stack top contains the Reverse Prefix Expression
            string prefix=st.top();
        // 4.Reverse the Expression to Get the Correct Prefix Expression
            reverse(prefix.begin(),prefix.end());
            return prefix;
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
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends