class Solution {
public:
    int delRow[4]={-1,0,+1,0};
    int delCol[4]={0,-1,0,+1};
    void dfs(int row,int col,int inClr,int clr,vector<vector<int>>&image,vector<vector<int>>&ans){
        // Color the Current Cell
        ans[row][col]=clr;
        // Size
        int n=image.size();
        int m=image[0].size();

        // Try All 4 Directions
        for(int i=0;i<4;i++)
        {
            int r=row+delRow[i];
            int c=col+delCol[i];
            // Check Valid (Range & Same Initial Color & Previously Not Colored)
            if((r>=0 && r<n && c>=0 && c<m) && (image[r][c]==inClr) && (ans[r][c]!=clr))
            dfs(r,c,inClr,clr,image,ans);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)    {
        vector<vector<int>>ans=image;
        int inClr=image[sr][sc];
        dfs(sr,sc,inClr,color,image,ans);
        return ans;
    }
};