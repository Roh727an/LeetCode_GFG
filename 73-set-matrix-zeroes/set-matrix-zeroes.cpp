class Solution {
public:
    void setZeroes(vector<vector<int>>& mattrix) {
        int n=mattrix.size();
        int m=mattrix[0].size();
        // Set Row & Column to -1
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mattrix[i][j]==0)
                {
                    // Set entire Row -1
                    for(int k=0;k<n;k++)
                    {
                        if(mattrix[k][j]!=0 && mattrix[k][j]!=1e9)
                        mattrix[k][j]=1e9;
                    }
                    // Set entire Column -1
                    for(int k=0;k<m;k++)
                    {
                        if(mattrix[i][k]!=0 && mattrix[i][k]!=1e9)
                        mattrix[i][k]=1e9;
                    }
                }
            }
        }
        // Change -1 to 0
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mattrix[i][j]==1e9)
                {
                    mattrix[i][j]=0;
                }
            }
        }
    }
};