// User function Template for Java

class Solution {
    public int[] BoundaryElements(int[][] matrix) {
        int n=matrix.length;
        int totalBoundaryEements=n>1?(n*2)+((n-2)*2):1;
        int ans[]=new int [totalBoundaryEements];
        int idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // First Row || Last Row
                if(i==0 || i==n-1){
                    ans[idx++]=matrix[i][j];
                }
                else if(j==0 || j==n-1){
                    ans[idx++]=matrix[i][j];
                }
            }
        }
        return ans;
    }
}