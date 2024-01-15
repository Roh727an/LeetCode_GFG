class Solution {
public:
void rec(int i,int n,vector<int>& nums,vector<int>temp,vector<vector<int>>&ans)
{
    if(i>=n)
    {
        ans.push_back(temp);
        return;
    }
    // Pick up
    temp.push_back(nums[i]);
    rec(i+1,n,nums,temp,ans);
    // Backtracks
    temp.pop_back();
    // Not Pick
    rec(i+1,n,nums,temp,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        rec(0,nums.size(),nums,temp,ans);
        return ans;
    }
};