class Solution {
public:
    int rec(int n){
        // Base Case
        if(n==1|| n==0)
        return 1;

        return rec(n-1)+rec(n-2);
    }
    int memo(int n,vector<int>&dp){
        // Base Case
        if(n==1|| n==0)
        return 1;

        if(dp[n]!=-1)
        return dp[n];

        return dp[n]=memo(n-1,dp)+memo(n-2,dp);
    }
    int climbStairs(int n) {
        // return rec(n);
        vector<int>dp(n+1,-1);
        
        return memo(n,dp);
    }
};