class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int search=target-nums[i];
            if(mp.find(search)!=mp.end()){
                return {i,mp[search]};
            }
            mp[nums[i]]=i;

        }
        return {-1,-1};
    }
};