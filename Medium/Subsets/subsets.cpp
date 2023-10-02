//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void rec(vector<vector<int>>&ans,vector<int>v,vector<int>ds,int idx,int n)
    {
        // Base Case
        if(idx>=n)
        {
            ans.push_back(ds);
            return;
        }
        // Pick & Recusive Call
        ds.push_back(v[idx]);
        rec(ans,v,ds,idx+1,n);
        // Pop
        // Not Pick & Recursive Call
        ds.pop_back();
        rec(ans,v,ds,idx+1,n);
    }
    vector<vector<int>> subsets(vector<int>& A)
    {
        //code here
        int n=A.size();
        vector<int>ds;
        int idx=0;
        vector<vector<int>> ans;
        rec(ans,A,ds,idx,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends