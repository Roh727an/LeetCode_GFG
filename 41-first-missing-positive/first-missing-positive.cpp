class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int small=1;
        for(int i=0;i<nums.size();i++)
        {
            if(small==nums[i])
            small++;
        }
        return small;
    }
};