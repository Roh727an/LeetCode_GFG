class Solution {
public:
    int search(vector<int>& nums, int target) {
        //1.Identify the Sorted Half
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        while(low<=high)
        {
        // Element Found
        if(nums[mid]==target)
        return mid;
        // Left Part is Sorted
        else if(nums[low]<=nums[mid])
        {
            // Check if Element is Present in The Left Part or Not
            if(nums[low]<=target && nums[mid]>=target)
            {
                // Move to Left
                high=mid-1;
            }
            // Move to Right
            else
            {
                low=mid+1;
            }
        }
        // Right Part is Srted
        else 
        {
            // Check if Element is Present in The Right Part or Not
            if(nums[mid]<=target && nums[high]>=target)
            {
                // Move to Right
                low=mid+1;
            }
            // Move to Left
            else
            {
                high=mid-1;
            }
        }
        // Update Mid
        mid=(low+high)/2;
        }
        // Element is Not Found
        return -1;
    }
};