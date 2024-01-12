//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void rec(int n,int i,string s,vector<string>&ans)
    {
        if(i>=n)
        {
         ans.push_back(s);
         return ;
        }
        
        // Pick Zero Or Leave
        s.push_back('0');
        rec(n,i+1,s,ans);
        s.pop_back();
        // PIck 1 When String is Empty or Last Character is not 1
        if(s.empty() || s.back()!='1')
        {
        s.push_back('1');
        rec(n,i+1,s,ans);
        s.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string>ans;
        rec(num,0,"",ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends