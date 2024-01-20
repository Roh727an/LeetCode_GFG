//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void rec(int row,int col,int n,string s,vector<vector<int>> &path,vector<string>&ans)
    {
        // Base Case
        if(row>=n || col>=n || col<0 || row<0 || path[row][col]!=1)
        return;
        
        if(row==n-1 && col==n-1)
        {
            ans.push_back(s);
            return;
        }
        
        // D L R U
        string dir="DLRU";
        int rowDir[4]={1,0,0,-1};
        int colDir[4]={0,-1,1,0};
        // Mark as Visited
        path[row][col]=-1;
        // Try All 4 Directions
        for(int i=0;i<4;i++)
        {
            
            s.push_back(dir[i]);
            int nRow=row+rowDir[i];
            int nCol=col+colDir[i];
            rec(nRow,nCol,n,s,path,ans);
            s.pop_back();
        }
        path[row][col]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        string s;
        rec(0,0,n,s,m,ans);
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