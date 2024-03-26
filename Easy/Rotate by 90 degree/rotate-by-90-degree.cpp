//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    void transposeMatrix(vector<vector<int>>& mat, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < m; j++)
                swap(mat[i][j], mat[j][i]);
        }
    }
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& mat, int n) 
    { 
        // code here 
        // 1.Transpose Matrix
        transposeMatrix(mat, n, n);
        // 2.Reverse Each Row
        for (int i = 0; i < n; i++) {
            int s = 0, e = n - 1;
            while (s < e) {
                swap(mat[s++][i], mat[e--][i]);
            }
        }
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends