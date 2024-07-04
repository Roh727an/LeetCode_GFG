class Solution {
public:
    bool check(vector<int>& nums) {
        int rotated=0;
        for(int i=0;i<nums.size();i++){
            // A[i] == B[(i+x) % A.length] (ROTATION LOGIC)
            if(nums[i]>nums[(i+1)%nums.size()])
            rotated++;

            if(rotated>1)
            return false;
        }
        return true;
    }
};