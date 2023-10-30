class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hashmap of {Number,Index}
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int number=nums[i];
            int need=target-number;
            // Search the Remaining into the Hash Map
            if(mp.find(need)!=mp.end())
            return {mp[need],i};
            // Number -> index
            mp[number]=i;
        }
        return {-1,-1};
    }
};