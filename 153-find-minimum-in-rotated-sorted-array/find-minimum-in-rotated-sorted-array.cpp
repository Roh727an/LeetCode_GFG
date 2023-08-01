class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int mid=(i+j)/2;
        while(i<j)
        {
            if(nums[mid]>nums[j])
            i=mid+1;
            else
            j=mid;

            mid=(i+j)/2;
        }
        return nums[mid];
    }
};