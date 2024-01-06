class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r1=0,c1=0,r2=n-1,c2=n-1;
        vector<vector<int>>matrix(n,vector<int>(n,-1));
        int ele=1;
        while(r1<=r2 && c1<=c2)
        {
            // C1 - C2
            for(int i=c1;i<=c2;i++)
            {
                matrix[r1][i]=ele;
                ele++;
            }
            r1++;
            // R1 - R2
            for(int i=r1;i<=r2;i++)
            {
                matrix[i][c2]=ele;
                ele++;
            }
            c2--;
            // We only traverse if it has at least a sningle row
            if(r1<=r2){
            // C2 - C1
            for(int i=c2;i>=c1;i--)
            {
                matrix[r2][i]=ele;
                ele++;
            }
            r2--;
            }

            // We only traverse if it has at least a sningle row
            if(c1<=c2)
            {
            // R2 - R1
            for(int i=r2;i>=r1;i--)
            {
                matrix[i][c1]=ele;
                ele++;
            }
            c1++;
            }
        }
        return matrix; 
    }
};