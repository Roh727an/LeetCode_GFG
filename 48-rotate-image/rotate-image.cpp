class Solution {
public:
    void transpose(vector<vector<int>>& m){
        int n=m.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            swap(m[i][j],m[j][i]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        // Transpose Matrix
        transpose(matrix);
        // Reverse Row of Matrix
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};