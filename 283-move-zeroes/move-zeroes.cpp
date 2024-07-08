class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Base Case
        if(nums.size()<=1)
        return ;
        int i=0,j=0;
        while(i<nums.size() && j<nums.size()){
            // Get the first zero 
            while(i<nums.size() && nums[i]!=0)
            i++;

            // Fisrt Zero found 
            j=i+1;

            // Find the first NonZero
            while(j<nums.size() && nums[j]==0 )
            j++;

            // First NonZero Found
            if(i<nums.size() && j<nums.size()){
            swap(nums[i],nums[j]);
            i++;
            j++;
            }
        }
    }
};