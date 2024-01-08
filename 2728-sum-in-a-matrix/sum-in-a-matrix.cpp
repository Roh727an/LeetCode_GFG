class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        int ans=0;
        // Sort each Row first
        for(int i=0;i<n;i++)
        {
            sort(nums[i].begin(),nums[i].end());
        }
        for(int j=m-1;j>=0;j--)
        {
            int maxEle=0;
            for(int i=0;i<n;i++)
            {
                maxEle=max(maxEle,nums[i][j]);
                nums[i][j]=-1;
            }
            ans+=maxEle;
        }
        return ans;
    }
};