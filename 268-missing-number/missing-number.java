class Solution {
    public int missingNumber(int[] nums) {
        int missingNo=nums.length;
        for(int i=0;i<nums.length;i++){
            missingNo^=(nums[i]^i);
        }
        return missingNo;
    }
}