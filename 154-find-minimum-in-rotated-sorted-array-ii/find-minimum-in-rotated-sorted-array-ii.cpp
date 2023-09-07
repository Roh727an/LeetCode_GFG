class Solution {
public:
    int findMin(vector<int>& nums) {
        // Brute Force
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        if(ans>nums[i])
        ans=nums[i];

        return ans;
    }
};