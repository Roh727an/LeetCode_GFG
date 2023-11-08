class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int Nsum=nums.size();
        for(int i=0;i<nums.size();i++)
        {
           sum+=nums[i];
           Nsum+=i; 
        }

        return Nsum-sum;
    }
};