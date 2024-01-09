class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        // Base
        // 1.a.If the Array Contains single elemnt then it is a Peak Element
        if(n==1)
        return 0;
        // b.Last element is Peak Element
        if(nums[n-1] > nums[n-2])
        return n-1;
        // c.First Element is Peak Element
        if(nums[0] > nums[1])
        return 0;

        // Search Space is 1 to n-2
        // Binary Search Logic
        int low=1,high=n-2;
        while(low<=high)
        {
            // Calculate mid
            int mid=(low+high)/2;

            // Check if Mid is Peak or Not
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            return mid;

            // If mid is in Decreasing Slope then Peak is on the Left Part
            if(nums[mid]>nums[mid+1])
            high=mid-1;
            // Else Peak is on the Right part
            else
            low=mid+1;
        }
        return -1;
    }
};