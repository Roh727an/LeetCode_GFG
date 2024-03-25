class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums)
        mp[x]++;

        vector<int>dup;
        for(auto it:mp){
            if(it.second>1)
            dup.push_back(it.first);
        }
        return dup;
    }
};