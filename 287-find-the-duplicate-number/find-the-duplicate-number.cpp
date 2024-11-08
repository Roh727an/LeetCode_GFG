class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int idx=abs(nums[i]);
            // If Visited
            if(nums[idx]<0)
            {
                ans=idx;
                break;
            }
            // Mark as Visited
            nums[idx]*=(-1);
        }
        return ans;
    }
};