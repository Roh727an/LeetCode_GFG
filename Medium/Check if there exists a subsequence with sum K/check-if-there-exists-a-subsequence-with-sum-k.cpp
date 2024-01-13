//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool rec(int i,int n,vector<int>& nums,int sum,int k)
    {
        // Base Case
        if(i>=n || sum>=k)
        {
            return sum==k;
        }
        // Pick an element
        if(nums[i]<=k)
        {
        sum=sum+nums[i];
        // Recursive Call with picked element
        if(rec(i+1,n,nums,sum,k))
        return true;
        // Pop the Element 
        sum=sum-nums[i];
        }
        // Recursive without picking element
        if(rec(i+1,n,nums,sum,k))
        return true;
        
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& nums, int k) {
        // Code here
        return rec(0,n,nums,0,k);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends