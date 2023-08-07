class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left=0,top=0,bottom=n-1,right=n-1;
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int cnt=1;
        while(left<=right && top<=bottom)
        {

        // Right Direction Print
        for(int i=left;i<=right;i++)
        {
            matrix[top][i]=cnt;
            cnt++;
        }
        top++;

        // Downwards Direction
        for(int i=top;i<=bottom;i++)
        {
            matrix[i][right]=cnt;
            cnt++;
        }
        right--;

        // Left Direction
        if(top<=bottom) //check if it is single row or not
        {
            for(int i=right;i>=left;i--)
            {
                matrix[bottom][i]=cnt;
                cnt++;
            }
            bottom--;
        }
        
        // Upward Direction
        if(left<=right) //Check if it is single column or not
        {
            for(int i=bottom;i>=top;i--)
            {
               matrix[i][left]=cnt;
               cnt++;
            }
            left++;
        }
        }
        return matrix;
    }
};