//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void rec(int idx,string &nums,vector<string>&ans)
    {
        if(idx>=nums.size())
        {
            ans.push_back(nums);
            return ;
        }
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
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>ans;
        rec(0,S,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends