class Solution {
public:
int FindMax(vector<vector<int>>& nums,int n,int col)
{
    int mx=-1;
    for(int i=0;i<n;i++)
    {
    mx=max(nums[i][col],mx);
    nums[i][col]=-1;
    }
    

    return mx;
}
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0;i<n;i++)
        {
            sort(nums[i].begin(),nums[i].end());
        }
        // cout<<"Matrix"<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     cout<<nums[i][j]<<" ";
        //     cout<<endl;
        // }
        int ans=0;
        for(int i=m-1;i>=0;i--)
        {
            // Pass Whole Column -> Last to First
            int max_Rows=FindMax(nums,n,i);

            // cout<<max_Rows<<" For "<<i<<endl;
            ans+=max_Rows;
        }

        return ans;
    }
};