class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int mid=(i+j)/2;
    // For Sorted Array a[low] < a[mid] & a[high] > a[mid]
        while(i<j)
        {
            //mid > high then rotated in right Part -> Get Minimum in Right Part
            if(nums[mid]>nums[j])
            i=mid+1;
            // Else rotated in left Part -> Get Minimum in left Part
            else
            j=mid;

            mid=(i+j)/2;
        }
        return nums[mid];
    }
};