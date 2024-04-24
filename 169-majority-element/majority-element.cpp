class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        // Count Freqency
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;
        // If any Element have>n/2 Frequency Return it (Major Element)
        for(auto it:mp){
            if(it.second > nums.size()/2)
            return it.first;
        }

        return -1;
    }
};