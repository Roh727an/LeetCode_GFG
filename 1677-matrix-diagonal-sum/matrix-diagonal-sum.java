class Solution {
    public int diagonalSum(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        //Diagonal Sum
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = i, y = m - 1 - j;
                // Primary diagonal
                if (i == j) {
                    sum += mat[i][j];
                    // secondary Diagonal
                    if (x == i && y != j && x < n && y >= 0) {
                        sum += mat[x][y];
                    }
                }
            }
        }
        return sum;
    }
}