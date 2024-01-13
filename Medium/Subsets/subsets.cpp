//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        void rec(int i,int n,vector<int>temp,vector<vector<int>>&ans,vector<int>& nums)
    {
        // Base Case
        if(i>=n)
        {
            ans.push_back(temp);
            return ;
        }
        // Pick an element
        temp.push_back(nums[i]);
        // Recursive Call with picked element
        rec(i+1,n,temp,ans,nums);
        // Pop the Element 
        temp.pop_back();
        // Recursive without picking element
        rec(i+1,n,temp,ans,nums);
    }
    vector<vector<int> > subsets(vector<int>& nums)
    {
        //code here
        vector<vector<int>>ans;
        vector<int>temp;
        rec(0,nums.size(),temp,ans,nums);
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