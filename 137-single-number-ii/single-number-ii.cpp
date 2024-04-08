class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Sorting Approch
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size()-1;i=i+3){
            if(nums[i]!=nums[i-1])
            return nums[i-1];
            if(nums[i]!=nums[i+1])
            return nums[i+1];
        }
        return nums[nums.size()-1];
    }
};