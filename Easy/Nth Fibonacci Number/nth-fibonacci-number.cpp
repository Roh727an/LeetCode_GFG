//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int f(int n,vector<int>&dp)
  {
    /*
    //   MEMOIZATION
    //   Base Case
    if(n<=1)
    return n;
    // Memoization Step2:Check if The Subproblem is ALready Solved Or Not
    if(dp[n]!=-1)
    return dp[n];
    // Memoization Step3:Store the Answer of Subproblem
    return dp[n]=f(n-1,dp)+f(n-2,dp);
    */
    
  }
  int mod =1000000007;
    int nthFibonacci(int n){
        // code here
        // Memoization Step1:Create a Dp Array of Size Subproblems
        vector<int>dp(n+1,-1);
        // TABULATION
        dp[0]=0;
        dp[1]=1;
        // return f(n,dp);
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]%mod+dp[i-2]%mod;
            dp[i]=dp[i]%mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends