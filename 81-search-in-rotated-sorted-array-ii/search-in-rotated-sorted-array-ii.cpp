class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        while(low<=high)
        {
            if(nums[mid]==target) 
            return true;

            // Shrink Search Space
            if(nums[mid]==nums[low] && nums[mid]==nums[high])
            {
            low++;
            high--;
            continue;
            }
            
            // Left Side Sorted
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<=target && nums[mid]>=target)
                high=mid-1;
                else
                low=mid+1;
            }
            else{
                if(nums[mid]<=target && nums[high]>=target)
                low=mid+1;
                else
                high=mid-1;
            }
             mid=(low+high)/2;
        }
        return false;
    }
};