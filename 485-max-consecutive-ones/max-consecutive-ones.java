class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxCnt=0,cnt=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]==0)
            {
                maxCnt=Math.max(maxCnt,cnt);
                cnt=0;
            }
            else
                cnt++;
        }
        return Math.max(maxCnt,cnt);
    }
}