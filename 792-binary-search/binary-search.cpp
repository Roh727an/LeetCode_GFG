class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=e/2-(s+e)/2;
        while(s<=e)
        {
            if(nums[mid]==target)
            return mid;

            else if(nums[mid] < target)
            {
                s=mid+1;
            }
            //nums[mid] > target
            else
            {
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return -1;
    }
};