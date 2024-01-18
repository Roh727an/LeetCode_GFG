class Solution {
public:
bool isValidMove(int r,int c,vector<string>grid,int n)
{
    // Check all 8 Directions
    // As we are filling column from left to right so,i only have to check left-up,left,left-down
    // lef-tup
    int row=r,col=c;
    while(row>=0 && col>=0)
    {
        if(grid[row][col]=='Q')
        return false;

        row--;
        col--;
    }
    // Left-Down
    row=r,col=c;
    while(row<n && col>=0)
    {
        if(grid[row][col]=='Q')
        return false;

        row++;
        col--;
    }
    // Left
    row=r,col=c;
    while(col>=0)
    {
        if(grid[row][col]=='Q')
        return false;
        col--;
    }

    return true;
}

void rec(int col,int n,vector<string>grid,vector<vector<string>>&ans)
{
    // Base Case
    if(col>=n)
    {
        ans.push_back(grid);
        return;
    }
    // Check for all rows of a particular Column
    for(int row=0;row<n;row++)
    {
        // if the Current Move is Valid
        if(isValidMove(row,col,grid,n))
        {
            // Mark the Move
            grid[row][col]='Q';
            // Recursive Call for next Column
            rec(col+1,n,grid,ans);
            // Backtracks
            grid[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>grid;
        string s(n,'.');
        for(int i=0;i<n;i++)
        grid.push_back(s);
        vector<vector<string>>ans;
        rec(0,n,grid,ans);
        return ans;
    }
};