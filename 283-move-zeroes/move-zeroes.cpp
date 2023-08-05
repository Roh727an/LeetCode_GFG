class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Intutuion-> Push NonZero First
        int non_zero_idx=0;
        // Iterate Over Array
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[non_zero_idx]);
                // Update  Non zero index
                non_zero_idx++;
            }
        }
    }
};