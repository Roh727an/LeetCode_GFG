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
    return memo(n-1,nums,dp);
    }
};