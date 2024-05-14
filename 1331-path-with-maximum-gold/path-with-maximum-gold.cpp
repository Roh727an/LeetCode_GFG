class Solution {
public:
int rowD[4]={0,1,0,-1};
int colD[4]={1,0,-1,0};
int rec(int row,int col,vector<vector<int>>& grid){
    int n=grid.size(),m=grid[0].size();
    // Base Case
    if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==0)
    return 0;

    // Visited Mark
    int currVal=grid[row][col];
    grid[row][col]=0;
    int maxi=currVal;

    // Go all 4 Direction
    for(int i=0;i<4;i++)
    {
        int nR=row+rowD[i];
        int nC=col+colD[i];
        // Recursive Call
        int recVal=rec(nR,nC,grid)+currVal;
        maxi=max(recVal,maxi);//Maximum 
    }
    // Backtracks
    grid[row][col]=currVal;
    return maxi;
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int maxGold=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    int val=rec(i,j,grid);
                    maxGold=max(maxGold,val);
                }
            }
        }
        return maxGold;
    }
};