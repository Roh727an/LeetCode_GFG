class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=(s+e)/2;
        while(s<e){
            if(nums[mid]>nums[e]){
            s=mid+1;
            }
            else
            e=mid;

            mid=(s+e)/2;
        }
        return nums[mid];
    }
};