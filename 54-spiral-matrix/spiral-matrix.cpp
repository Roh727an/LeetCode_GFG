class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,top=0,bottom=n-1,right=m-1;
        vector<int>order;
        while(left<=right && top<=bottom)
        {

        // Right Direction Print
        for(int i=left;i<=right;i++)
        {
            order.push_back(matrix[top][i]);
        }
        top++;

        // Downwards Direction
        for(int i=top;i<=bottom;i++)
        {
            order.push_back(matrix[i][right]);
        }
        right--;

        // Left Direction
        if(top<=bottom) //check if it is single row or not
        {
            for(int i=right;i>=left;i--)
            {
                order.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        
        // Upward Direction
        if(left<=right) //Check if it is single column or not
        {
            for(int i=bottom;i>=top;i--)
            {
                order.push_back(matrix[i][left]);
            }
            left++;
        }
        }
        return order;
    }
};