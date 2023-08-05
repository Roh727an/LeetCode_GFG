class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        // Xor all Numbers Present in the Array 
        for(int i=0;i<nums.size();i++)
        {
            ans^=nums[i];
        }
        // Xor all Numbers from 0-nums.size()
        for(int i=0;i<=nums.size();i++)
        {
            ans^=i;
        }
        return ans;
    }
};