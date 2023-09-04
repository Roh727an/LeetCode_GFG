//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        // 1.Create A Stack
        stack<char>st;
        // 2.Push Open Bracket & Operators Only
        for(int i=0;i<s.length();i++)
        {
            // Closed Bracket
            if(s[i]==')')
            {
                if(st.top()=='(')
                return true;
                while(!st.empty() && st.top()!='(')
                {
                    st.pop();
                }
                if(!st.empty())
                st.pop();
            }
            else if(s[i]>='a' && s[i]<='z')
            continue;
            // Open Bracket & Operator
            else
            st.push(s[i]);
        }
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends