class Solution {
public:
    int firstOccurance(vector<int>& nums, int target){
         int s=0,e=nums.size()-1;
         int fo=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
            fo=mid;
            e=mid-1;
            }
            else if(nums[mid]>target)
            e=mid-1;
            else // Move Right
            s=mid+1;
        }
        return fo;
    }
    int lastOccurance(vector<int>& nums, int target){
         int s=0,e=nums.size()-1;
         int lo=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
            lo=mid;
            s=mid+1;
            }
            else if(nums[mid]>target)
            e=mid-1;
            else // Move Right
            s=mid+1;
        }
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurance(nums,target),lastOccurance(nums,target)};
    }
};