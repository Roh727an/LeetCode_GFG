class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int>mp;
        int ans=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            mp[nums[i]]++;
            else
            {
                if(mp.find(-1*nums[i])!=mp.end())
                ans=nums[i];
            }
        }
        return ans;
    }
};