//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isValidMove(int r,int c,vector<string>grid,int n)
{
    // Check all 8 Directions
    // As we are filling column from left to right so,i only have to check left-up,left,left-down
    // lef-tup
    int row=r,col=c;
    while(row>=0 && col>=0)
    {
        if(grid[row][col]=='Q')
        return false;

        row--;
        col--;
    }
    // Left-Down
    row=r,col=c;
    while(row<n && col>=0)
    {
        if(grid[row][col]=='Q')
        return false;

        row++;
        col--;
    }
    // Left
    row=r,col=c;
    while(col>=0)
    {
        if(grid[row][col]=='Q')
        return false;
        col--;
    }

    return true;
}

void rec(int col,int n,vector<string>grid,vector<vector<int>>&ans,vector<int>pos)
{
    // Base Case
    if(col>=n)
    {
        ans.push_back(pos);
        return;
    }
    // Check for all rows of a particular Column
    for(int row=0;row<n;row++)
    {
        // if the Current Move is Valid
        if(isValidMove(row,col,grid,n))
        {
            // Mark the Move
            grid[row][col]='Q';
            pos.push_back(row+1);
            // Recursive Call for next Column
            rec(col+1,n,grid,ans,pos);
            // Backtracks
            grid[row][col]='.';
            pos.pop_back();
        }
    }
}
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<string>grid;
        string s(n,'.');
        for(int i=0;i<n;i++)
        grid.push_back(s);
        vector<vector<int>>ans;
        vector<int>pos;
        rec(0,n,grid,ans,pos);
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