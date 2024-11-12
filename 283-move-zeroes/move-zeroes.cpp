class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZero=0;
        for(int zero=0;zero<nums.size();zero++){
            if(nums[zero]!=0){
                swap(nums[zero],nums[nonZero]);
                nonZero++;
            }
        }
    }
};