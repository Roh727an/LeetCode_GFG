//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int memo(int idx,int *nums,vector<int>& dp)
    {
    // Base Case
    if(idx==0)
    return nums[idx];
    if(idx<0)
    return 0;
    if(dp[idx]!=-1)
    return dp[idx];
    // We Have Two Choices,either Pick or Not Pick
    int pick=nums[idx]+memo(idx-2,nums,dp);
    int notPick=0+memo(idx-1,nums,dp);

    // Return Maxium of it
    return dp[idx]=max(pick,notPick);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n+1,-1);
    return memo(n-1,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends