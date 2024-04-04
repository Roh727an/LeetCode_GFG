class Solution {
public:
    void rec(int idx,int n,vector<int> nums,vector<int>ds,vector<vector<int>>&ans){
        if(idx>=n)
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        rec(idx+1,n,nums,ds,ans);
        ds.pop_back();
        rec(idx+1,n,nums,ds,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // Recursion
        vector<vector<int>>ans;
        vector<int>ds;
        int n=nums.size();
        rec(0,n,nums,ds,ans);
        return ans;
    }
};