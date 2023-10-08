//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(int row,int col,vector<string>grid,int n)
{
    // Check all 8 Directions
    // AS we Filling Up Queens from Left To Right Column then We Just Have to Check 3 Directions only-
    // 1.Left
    int r=row;
    int c=col;
    // Up-Left
    while(r>=0 && c>=0)
    {
        if(grid[r][c]!='.')
        return false;
        c--;
        r--;
    }
     r=row;
     c=col;
    // LEft
    while(c>=0)
    {
        if(grid[r][c]!='.')
        return false;
        c--;
    }
    
     r=row;
     c=col;
    // Down-Left
    while(r<n && c>=0)
    {
        if(grid[r][c]!='.')
        return false;
        c--;
        r++;
    }

    return true;
}
void rec(int col,vector<string>grid,vector<vector<int>>&ans,vector<int>queens,int n)
{
    // Base Case
    if(col>=n)
    {
        ans.push_back(queens);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isValid(i,col,grid,n))
        {
            queens.push_back(i+1);
            grid[i][col]='Q';
            rec(col+1,grid,ans,queens,n);
            grid[i][col]='.';
            queens.pop_back();
        }
    }
}
    vector<vector<int>> nQueen(int n) {
        // code here
        // 1.Create the ChessBoard
        vector<string>grid;
        string s(n,'.');
        for(int i=0;i<n;i++)
        grid.push_back(s);
        vector<vector<int>>ans;
        vector<int>queens;
        rec(0,grid,ans,queens,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends