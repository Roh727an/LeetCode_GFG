//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int rdir[4]={1,0,0,-1};
    int cdir[4]={0,-1,1,0};
    void rec(int row,int col,int n,vector<vector<int>>& m,vector<string>& ans,string path,vector<vector<int>>& vis)
    {
        //Base Case
        if(row==n-1 && col==n-1)
        {
            ans.push_back(path);
            return ;
        }
        // Check Four Direction -> Down,Left,Right,Up
        string dir="DLRU";
        for(int i=0;i<4;i++)
        {
            int nrow=row+rdir[i];
            int ncol=col+cdir[i];
            // Check -Bound && Not Visited && Can Move
            if(nrow<n && nrow>=0 && ncol<n && ncol>=0 & !vis[nrow][ncol] && m[nrow][ncol]==1)
            {
                // Mark as Visited
                vis[row][col]=1;
                // Recursive Call for Next Move
                rec(nrow,ncol,n,m,ans,path+dir[i],vis);
                // Unvisited when Backtracks
                vis[row][col]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==1)
        rec(0,0,n,m,ans,"",vis);

        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends