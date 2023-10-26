class Solution {
public:
// RECURSION
    int rec(int n)
    {
        // Base Case
        if(n==1 || n==0)
        return 1;

        return rec(n-1)+rec(n-2);
    }
    // MEMOIZATION
    int Memo(int n,vector<int>dp)
    {
        // Base Case
        if(n==1 || n==0)
        return 1;
        if(dp[n]!=-1)
        return dp[n];

        return dp[n]=Memo(n-1,dp)+Memo(n-2,dp);
    }
    int climbStairs(int n) {
        /*
        // RECURSION
        // return rec(n);

        // MEMOIZATION
        vector<int>dp(n+1,-1);
        // return Memo(n,dp);
        // TABULATION
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        */
        // SPACE OPTIMIZATION
        int prev2=1;
        int prev=1;
        for(int i=2;i<=n;i++)
        {
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};