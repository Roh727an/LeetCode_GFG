class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Count Values & Replace Values
        int zero=0;
        int one=0;
        int two=0;
        // Count Values
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            zero++;
            else if(nums[i]==1)
            one++;
            else
            two++;
        }
        // Replace Values
        int idx=0;
        while(zero--)
        {
            nums[idx++]=0;
        }
        while(one--)
        {
            nums[idx++]=1;
        }
        while(two--)
        {
            nums[idx++]=2;
        }
    }
};