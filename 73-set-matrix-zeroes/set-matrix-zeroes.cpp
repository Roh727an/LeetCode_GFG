class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // Approch 3 : Row & Column Approch
        vector<int>row(n,-1);
        vector<int>col(m,-1);

        // 1.Traverse the Matrix & Mark accordingly into Row & Col Array
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        // 2.Taraverse again & Convert 0
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]==0 || col[j]==0)
                matrix[i][j]=0;
            }
        }
    }
};