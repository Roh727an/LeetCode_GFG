class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int X) {
        int n=mat.size();
        int m=mat[0].size();
        int s=0;
	    int e=n*m-1;
	    while(s<=e){
	        int mid=(s+e)/2;
	       // Get the row & col of Mid from 2d Matrix
	        int mid_row=mid/m;
	        int mid_col=mid%m;
	        
	        if(mat[mid_row][mid_col]==X)
	        return 1;
	        
	        else if(mat[mid_row][mid_col]>X)
	        e=mid-1;
	        else
	        s=mid+1;
	    }
	    return 0;
    }
};