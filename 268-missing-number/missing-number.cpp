class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int miss=0;
        for(int i=0;i<nums.size();i++)
        {
            if(miss!=nums[i])
            return miss;
            else
            miss++;
        }
        return miss;
    }
};