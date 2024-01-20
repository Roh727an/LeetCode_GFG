class Solution {
public:
// Recursive Approch
void rec(int idx,int n,vector<int> nums,vector<vector<int>>&ans)
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

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        rec(0,n,nums,ans);
        return ans;
    }
};