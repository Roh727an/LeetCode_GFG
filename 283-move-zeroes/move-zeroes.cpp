class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int>q;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            q.push(nums[i]);
        }
        int i=0;
        for(i=0;i<nums.size()&& !q.empty();i++){
            nums[i]=q.front();
            q.pop();
        }
        for(int j=i;j<nums.size();j++)
        nums[j]=0;
    }
};