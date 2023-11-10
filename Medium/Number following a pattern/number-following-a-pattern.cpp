//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string pattern;
        stack<int>st;
        int n=S.length();
        // Traverse the Given String
        for(int i=0;i<=n;i++){
            // Push index+1 into Stack
            st.push(i+1);
            // If it is Incement or Out of Bound
            if(i==n || S[i]=='I'){
                // Pop till Stack Becomes Empty & Store Corresponding in Ans
                while(!st.empty()){
                    pattern.push_back('0'+st.top());
                    st.pop();
                }
            }
        }
        return pattern;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends