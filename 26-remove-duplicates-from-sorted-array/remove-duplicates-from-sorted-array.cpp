class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nondup=0,dup=nondup+1;
        while(nondup<dup && dup<nums.size()){
            if(nums[nondup]!=nums[dup]){
            nums[nondup+1]=nums[dup];
            nondup++;
            }
            dup++;
        }
        return nondup+1;
    }
};