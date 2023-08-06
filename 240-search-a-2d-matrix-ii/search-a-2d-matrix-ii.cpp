class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row_pointer=0;
        int col_pointer=m-1;
        while(row_pointer<n && col_pointer>=0)
        {

            if(matrix[row_pointer][col_pointer]==target)
            return true;
            // It is Higher than target
            if(matrix[row_pointer][col_pointer]>target)
            col_pointer--;
            else
            row_pointer++;
        }
        return false;
    }
};