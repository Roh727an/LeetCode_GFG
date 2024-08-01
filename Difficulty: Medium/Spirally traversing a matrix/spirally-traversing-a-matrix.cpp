//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int> ans;
        
        int r1 = 0, c1 = 0, r2 = mat.size() - 1, c2 = mat[0].size() - 1;
        while (r1 <= r2 && c1 <= c2) {
            // First Row -> c1 -> c2
            for (int i = c1; i <= c2; i++) {
                ans.push_back(mat[r1][i]);
            }
            r1++;

            // Last Column -> r1 -> r2
            for (int i = r1; i <= r2; i++) {
                ans.push_back(mat[i][c2]);
            }
            c2--;

            // Last Row-> c2 -> c1
            if (r1 <= r2) {
                for (int i = c2; i >= c1; i--) {
                    ans.push_back(mat[r2][i]);
                }
                r2--;
            }

            // First Column -> r2 -> r1
            if (c1 <= c2) {
                for (int i = r2; i >= r1; i--) {
                    ans.push_back(mat[i][c1]);
                }
                c1++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends