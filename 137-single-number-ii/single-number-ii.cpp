class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Concept of Buckets
        int single=0,twice=0;
        for(int i=0;i<nums.size();i++){
            single=((single^nums[i])&(~twice));
            twice=((twice^nums[i]) & (~single));
        }
        return single;
    }
};