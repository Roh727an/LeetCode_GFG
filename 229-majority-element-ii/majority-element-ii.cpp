class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // APPROCH -> HASHMAP
        int n=nums.size();
        // Store the Frequency of Elements
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto it:mp)
        {
            if(it.second > n/3 )
            ans.push_back(it.first);
        }
        return ans;
    }
};