//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
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

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends