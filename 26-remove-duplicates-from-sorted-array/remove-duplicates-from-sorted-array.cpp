class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;
        for(int i=1;i<nums.size();i++)
        {
            // Non-Duplicate
            if(nums[idx]!=nums[i]){
                nums[idx+1]=nums[i];
                idx++;
            }
        }
        return idx+1;
    }
};