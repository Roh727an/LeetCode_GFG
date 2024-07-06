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
    int tabulation(int n){
        vector<int>dp(n+1,-1);
        // Base Case
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];

        return dp[n];
    }
    int climbStairs(int n) {
        // return rec(n);
        // vector<int>dp(n+1,-1);
        // return memo(n,dp);

        return tabulation(n);
    }
};