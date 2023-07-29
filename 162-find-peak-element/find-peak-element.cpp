class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans=-1;
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        /*
               >   >      
        1 2 3 4 |8| 2 4 5
        Normally-> arr[mid]<arr[mid+1]
        But for Peak index-> arr[mid]>arr[mid+1]=> mid can be our Peak Index
        */
        while(low<high)
        {

            if(nums[mid]>nums[mid+1])
            {
                // Left Side include Mid
                high=mid;
            }
            else
            {
                // Right Side exclude mid
                low=mid+1;
            }
            // Update Mid
            mid=(low+high)/2;
        }
        return mid;
    }
};