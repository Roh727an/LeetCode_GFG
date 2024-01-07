class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Approch 2 : Queue Approch
        // queue<row,col>q
        queue<pair<int,int>>q;
        int n=matrix.size();
        int m=matrix[0].size();
        // 1.Store all Indexes of 0s
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        // 2.Put an element from Queue & Make that row & Column 0
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            // Make the Row 0
            for(int i=0;i<m;i++)
            {
                matrix[row][i]=0;
            }
            // Make the col 0
            for(int i=0;i<n;i++)
            {
                matrix[i][col]=0;
            }
        }
    }
};