class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //  Start to End KADANE'S ALGORITHM
        int n=nums.size();
        int sum=1;
        int maxSum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum*=nums[i];
            // Update
            if(sum>maxSum)
            maxSum=sum;

            // Reset
            if(sum==0)
            sum=1;
        }
        //  End to Start KADANE'S ALGORITHM
        sum=1;
        for(int i=n-1;i>=0;i--)
        {
            sum*=nums[i];
            // Update
            if(sum>maxSum)
            maxSum=sum;

            // Reset
            if(sum==0)
            sum=1;
        }
        return maxSum;
    }
};