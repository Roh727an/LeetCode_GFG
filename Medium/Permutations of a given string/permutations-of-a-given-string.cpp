//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void rec(int idx,string &nums,set<string>&ans)
    {
        if(idx>=nums.size())
        {
            ans.insert(nums);
            return ;
        }
        // Iterate Over the Array from idx To N
        for(int i=idx;i<nums.size();i++)
        {
            // Swap ith element with index element
            swap(nums[idx],nums[i]);
            // Recursive Call
            rec(idx+1,nums,ans);
            // Backtracks
            swap(nums[idx],nums[i]);
        }
    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		set<string>st;
        rec(0,S,st);
        vector<string>ans(st.begin(),st.end());
        return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends