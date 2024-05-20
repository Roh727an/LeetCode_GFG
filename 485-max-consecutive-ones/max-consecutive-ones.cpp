class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,maxcnt=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
            maxcnt=max(cnt,maxcnt);
            cnt=0;
            }
            else
            cnt++;
        }
        maxcnt=max(cnt,maxcnt);
        return maxcnt;
    }
};