class Solution {
public:
void rec(int i,int n,vector<int>& nums,vector<int>temp,set<vector<int>>&ans)
{
    if(i>=n)
    {
        sort(temp.begin(),temp.end());
        ans.insert(temp);
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         
         vector<int>temp;
         set<vector<int>>st;
         rec(0,nums.size(),nums,temp,st);
         vector<vector<int>>ans(st.begin(),st.end());
         return ans;
    }
};