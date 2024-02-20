//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
bool rec(string A,vector<string>&B)
    {
        // Base Case
        if(A.size()==0)
        return true;

        // Check all Possible Substring from A
        for(int i=1;i<=A.length();i++)
        {
            string sub=A.substr(0,i);
            // Check if the Substring is Present in the Directory or Not
            int flag=0;
            for(int j=0;j<B.size();j++)
            {
                if(B[j]==sub)
                {
                    flag=1;
                    break;
                    // Substring is Found in the Directory So We Can Move Further
                }
            }
            // Call Further Check & If Found then Return true
            if(flag==1 && rec(A.substr(i,A.length()-i),B))
            return true;
        }
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        return rec(A,B);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends