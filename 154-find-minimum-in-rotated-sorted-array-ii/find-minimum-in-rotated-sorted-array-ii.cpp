class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        // Brute Force -> Linear Search
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        if(ans>nums[i])
        ans=nums[i];
        return ans;
        */
        // Optimised Solution -> Binary Search
        int n=nums.size();
        int l=0;
        int r=n-1;
        int mid=(r+l)/2;
        while(l<r)
        {
            // mid is Greater than right -> Move Left to mid+1
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            // mid is Smaller than right -> Move Right to mid
            else if(nums[mid]<nums[r])
            {
                r=mid;
            }
            else
            r--;
            // Update Mid
            mid=(r+l)/2;
        }
        return nums[l];
    }
};