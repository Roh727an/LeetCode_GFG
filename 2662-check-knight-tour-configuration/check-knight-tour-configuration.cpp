class Solution {
public:
bool rec(int row,int col,int move,int n,vector<vector<int>>& grid){
    
    // NOT FOUND || OUT OF BOUND CASE
    if(row>=n || col>=n || row<0 || col <0 || grid[row][col]!=move)
    return false;

    // Base Case
    if(move==n*n-1)
    return true;

    // Try all 8 Directions
    return rec(row+2,col+1,move+1,n,grid)||
    rec(row+2,col-1,move+1,n,grid)||
    rec(row-2,col+1,move+1,n,grid)||
    rec(row-2,col-1,move+1,n,grid)||
    rec(row+1,col-2,move+1,n,grid)||
    rec(row-1,col-2,move+1,n,grid)||
    rec(row+1,col+2,move+1,n,grid)||
    rec(row-1,col+2,move+1,n,grid);
}
    bool checkValidGrid(vector<vector<int>>& grid) {
        int move=0;
        int n=grid.size();
        return rec(0,0,move,n,grid);
    }
};