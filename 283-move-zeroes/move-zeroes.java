// import java.util.Collections;
class Solution {
    public void moveZeroes(int[] nums) {
        int nonZero=0;
        int zero=0;
        while(zero<nums.length){
            if(nums[zero]!=0)
            {
                // Swap
                int temp=nums[zero];
                nums[zero]=nums[nonZero];
                nums[nonZero]=temp;
                nonZero++;
            }
            zero++;
        }
    }
}