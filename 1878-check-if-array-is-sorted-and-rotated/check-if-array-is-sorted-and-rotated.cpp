class Solution {
public:
    bool check(vector<int>& nums) {
        int rt=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            // Rotation Logic
            if(nums[i]>nums[(i+1)%n])
            rt++;

            if(rt>1)
            return false;
        }
        return true;
    }
};