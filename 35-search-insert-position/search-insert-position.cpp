class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=n;
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        while(s<=e){
            if(nums[mid]==target)
            return mid;

            if(nums[mid]>target){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
            // UPDATE MID
            mid=(s+e)/2;
        }
        return ans;
    }
};