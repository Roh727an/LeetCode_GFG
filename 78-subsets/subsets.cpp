class Solution {
public:
void rec(int idx,vector<int>nums,vector<int>temp,vector<vector<int>>&ans){
    if(idx>=nums.size()){
        ans.push_back(temp);
        return ;
    }
    temp.push_back(nums[idx]);
    rec(idx+1,nums,temp,ans);
    temp.pop_back();
    rec(idx+1,nums,temp,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        rec(0,nums,temp,ans);
        return ans;
    }
};