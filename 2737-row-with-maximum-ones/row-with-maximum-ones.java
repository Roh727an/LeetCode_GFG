class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int count=0;
        int maxCount=-1;
        int row=-1;
        for(int i=0;i<mat.length;i++)
        {
            count=0;
            for(int j=0;j<mat[0].length;j++)
            {
                if(mat[i][j]==1)
                count++;
            }
            if(maxCount<count){
                maxCount=count;
                row=i;
            }
        }
        int ans[]={row,maxCount};
        return ans;
    }
}