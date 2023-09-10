//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        // 1.Create a Stack
        stack<int>st;
        // 2.Scan the Postfix Expression from left to right
        for(int i=0;i<S.length();i++)
        {
            // a.If operand Comes then Push into Stack
            if(S[i]>='0' && S[i]<='9')
            st.push(S[i]-'0');
            // b.If Operator Comes then Take out First two Operand From Stack & do Operation on them as (op2 op op1) & Push that value into Stack
            else
            {
                int A=st.top();
                st.pop();
                int B=st.top();
                st.pop();
                // Operator wise Operation
                if(S[i]=='^')
                st.push(pow(B,A));
                else if(S[i]=='+')
                st.push(B+A);
                else if(S[i]=='-')
                st.push(B-A);
                else if(S[i]=='*')
                st.push(B*A);
                else if(S[i]=='/')
                st.push(B/A);
            }
        }
        // 3.After Scan, the Stack Top Contains the Postfix Evaluation Value 
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends