class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
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
        */
        // OPTIMAL SOLUTION
        int n=nums.size();
        int sum=n*(n+1)/2;
        for(int i=0;i<n;i++){
            sum-=nums[i];
        }
        return sum;

    }
};