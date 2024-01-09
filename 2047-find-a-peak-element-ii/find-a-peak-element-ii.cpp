class Solution {
public:
// Returns Max Row 
int maxEleCol(vector<vector<int>>& mat,int n,int m,int col)
{
    int maxEle=INT_MIN;
    int idx=-1;
    for(int i=0;i<n;i++)
    {
        if(mat[i][col]>maxEle)
        {
            maxEle=mat[i][col];
            idx=i;
        }
    }
    return idx;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int s=0;
        int e=m-1;
        // Binary Search in Each Column
        while(s<=e)
        {
            int mid=(s+e)/2;
            // Row will be maxium element of the Column
            int row=maxEleCol(mat,n,m,mid);
            // As we Take the Largest element in the Column so we ddid have to check for upper & Lower Adjacent Element
            // We simply check left & Right
            int left= mid-1 >= 0 ? mat[row][mid-1]:-1;
            int right= mid+1 < m ? mat[row][mid+1]:-1;
            // If current element is Peak
            if(mat[row][mid] > left && mat[row][mid] > right)
            return {row,mid};
            else if(mat[row][mid] < left){
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return {-1,-1};
    }
};