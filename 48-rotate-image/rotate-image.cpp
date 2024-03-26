class Solution {
public:
void transposeMatrix(vector<vector<int>>& mat, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
            swap(mat[i][j], mat[j][i]);
    }
}
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
    // 1.Transpose Matrix
    transposeMatrix(mat, n, m);
    // 2.Reverse Each Row
    for (int i = 0; i < n; i++)
    {
        int s = 0, e = m - 1;
        while (s < e)
        {
            swap(mat[i][s++], mat[i][e--]);
        }
    }
    }
};