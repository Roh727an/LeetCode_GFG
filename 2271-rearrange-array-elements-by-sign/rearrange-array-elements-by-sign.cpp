class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            pos.push_back(nums[i]);
            else
            neg.push_back(nums[i]);
        }
        vector<int>ans(nums.size());
        int p=0,n=0;
        for(int i=0;i<nums.size();i++)
        {
            // Even
            if(i%2==0)
            ans[i]=pos[p++];
            else 
            ans[i]=neg[n++];
        }
        return ans;
    }
};