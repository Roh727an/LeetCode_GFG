class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int r1=0,c1=0,r2=n-1,c2=m-1;
        vector<int>ans;
        while(r1<=r2 && c1<=c2)
        {
            // C1 - C2
            for(int i=c1;i<=c2;i++)
            {
                ans.push_back(matrix[r1][i]);
            }
            r1++;
            // R1 - R2
            for(int i=r1;i<=r2;i++)
            {
                ans.push_back(matrix[i][c2]);
            }
            c2--;
            // We only traverse if it has at least a sningle row
            if(r1<=r2){
            // C2 - C1
            for(int i=c2;i>=c1;i--)
            {
                ans.push_back(matrix[r2][i]);
            }
            r2--;
            }

            // We only traverse if it has at least a sningle row
            if(c1<=c2)
            {
            // R2 - R1
            for(int i=r2;i>=r1;i--)
            {
                ans.push_back(matrix[i][c1]);
            }
            c1++;
            }
        }
        return ans;
    }
};