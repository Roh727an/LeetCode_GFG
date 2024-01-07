class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // Approch 4 : Optimized Approch
        // vector<int>row(n,-1); -> matrix[0][..]
        // vector<int>col(m,-1);-> matrix[..][0]
        int col0=1; //matrix[0][0] as Column Array

    // 1.Traverse the Matrix & Mark accordingly into Row & Col Array
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    // Mark the i'th Row
                    matrix[i][0]=0;
                    // Mark the j'th Column
                    if(j!=0)
                    matrix[0][j]=0;
                    else
                    col0=0;
                }
            }
        }
        // 2.Taraverse again without first row & Column (HashRow & HashColumn)
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]!=0)
                {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                matrix[i][j]=0;
                }
            }
        }

        // Traverse First Column Accoringly
        if(matrix[0][0]==0)
        {
            // First row will be Zero
            for(int i=0;i<m;i++)
            {
                matrix[0][i]=0;
            }
        }
        if(col0==0)
        {
          // First col will be Zero
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=0;
            }  
        }
    }
};