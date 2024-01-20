//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void rec(int idx,int n,string nums,vector<string>&ans)
{
    // Base Case
    if(idx >= n)
    {
        ans.push_back(nums);
        return;
    }

    for(int i=idx;i<n;i++)
    {
            swap(nums[i],nums[idx]);
            rec(idx+1,n,nums,ans);
            swap(nums[i],nums[idx]);
    }
}
    vector<string> permutation(string S)
    {
        //Your code here
        int n=S.length();
        vector<string>ans;
        rec(0,n,S,ans);
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