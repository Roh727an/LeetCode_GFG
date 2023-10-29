class Solution {
public:
int memo(int idx,vector<int>& nums,vector<int>& dp)
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
    int rob(vector<int>& nums) {
        // MEMOIZATION
    int n=nums.size();
    vector<int>dp(n+1,-1);
    // return memo(n-1,nums,dp);
    // TABULATION
    dp[0]=nums[0];
    dp[1]=0;
    for(int i=1;i<n;i++)
    {
        int pick=nums[i];
        // Edge Case
        if(i>1)
        pick+=dp[i-2];

        int nonPick=0+dp[i-1];

        dp[i]=max(pick,nonPick);
    }
    return dp[n-1];

    // SPACE OPTIMIZATION
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++)
    {
        int pick=nums[i];
        // Edge Case
        if(i>1)
        pick+=prev2;

        int nonPick=0+prev;

        int curr=max(pick,nonPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
    }
};