class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>>ans;
     unordered_map<int,int>mp;   
     for(int i=0;i<nums.size();i++){
        //  Check if we need new Row or not
        mp[nums[i]]++;
        if(mp[nums[i]] > ans.size())
        {
            ans.push_back({});
        }
        // PUSH INTO ROW
        int row=mp[nums[i]]-1;
        ans[row].push_back(nums[i]);
     }
    return ans;
    }
};