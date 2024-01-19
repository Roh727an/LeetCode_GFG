class Solution {
public:
      bool rec(int row,int col,int idx,vector<vector<char>> &board, string word,int n,int m)
    {
        // Base Case
        if(idx==word.length())
            return true;

        // Out Of Bound
        if(row<0 || col <0 || row>=n || col>=m || board[row][col]!=word[idx])
            return false;
        bool ans=false;
            // Change the Caracter to Specail as it is Visited
            board[row][col]='*';
            // Check all 4 directions
            ans=rec(row+1,col,idx+1,board,word,n,m)|| rec(row-1,col,idx+1,board,word,n,m) || rec(row,col+1,idx+1,board,word,n,m) || rec(row,col-1,idx+1,board,word,n,m);
            // Backtracs
            board[row][col]=word[idx];
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
 
       int index=0;
       int n=board.size();
       int m=board[0].size();
    //    Seach each Cell in The Board
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]==word[index])
            if(rec(i,j,index,board,word,n,m))
            return true;
        }
    }
    return false;
    }
};