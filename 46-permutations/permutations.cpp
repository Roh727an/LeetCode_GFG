class Solution {
public:
void rec(int idx,int n,vector<int>pm,vector<int> nums,vector<int> vis,vector<vector<int>>&ans)
{
    // Base Case
    if(idx >= n || pm.size() == n)
    {
        ans.push_back(pm);
        return;
    }

    for(int i=0;i<n;i++)
    {
        // Not Visited
        if(vis[i]==0)
        {
            pm.push_back(nums[i]);
            vis[i]=1;
            rec(idx+1,n,pm,nums,vis,ans);
            vis[i]=0;
            pm.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>visited(n,0);
        vector<vector<int>>ans;
        vector<int>temp;
        rec(0,n,temp,nums,visited,ans);
        return ans;
    }
};