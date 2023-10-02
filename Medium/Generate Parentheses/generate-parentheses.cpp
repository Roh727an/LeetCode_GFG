//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void rec(vector<string>&ans,int open,int close,int n,string s)
    {
        // Base Case
        if(open==n && close==n)
        {
            ans.push_back(s);
            return ;
        }
        // We add Openning Bracket till open is Less than N
        if(open<n)
        {
        s.push_back('(');
        rec(ans,open+1,close,n,s);
        s.pop_back();
        }
        // We add Closing Bracket till close is Less than open
        if(close<open)
        {
        s.push_back(')');
        rec(ans,open,close+1,n,s); 
        s.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
    vector<string>ans;
    rec(ans,0,0,n,"");
    return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends