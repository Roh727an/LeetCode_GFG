class Solution {
public:
    bool isValid(int row,int col,vector<string>grid,int n)
{
    // Check all 8 Directions
    // AS we Filling Up Queens from Left To Right Column then We Just Have to Check 3 Directions only-
    // 1.Left
    int r=row;
    int c=col;
    // Up-Left
    while(r>=0 && c>=0)
    {
        if(grid[r][c]!='.')
        return false;
        c--;
        r--;
    }
     r=row;
     c=col;
    // LEft
    while(c>=0)
    {
        if(grid[r][c]!='.')
        return false;
        c--;
    }
    
     r=row;
     c=col;
    // Down-Left
    while(r<n && c>=0)
    {
        if(grid[r][c]!='.')
        return false;
        c--;
        r++;
    }

    return true;
}
void rec(int col,vector<string>grid,vector<vector<string>>&ans,int n)
{
    // Base Case
    if(col>=n)
    {
        ans.push_back(grid);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isValid(i,col,grid,n))
        {
            grid[i][col]='Q';
            rec(col+1,grid,ans,n);
            grid[i][col]='.';
        }
    }
}
    int totalNQueens(int n) {
        vector<string>grid;
        string s(n,'.');
        for(int i=0;i<n;i++)
        grid.push_back(s);
        vector<vector<string>>ans;

        rec(0,grid,ans,n);
        return ans.size();
    }
};