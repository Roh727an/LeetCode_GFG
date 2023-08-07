//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,top=0,bottom=n-1,right=m-1;
        vector<int>order;
        while(left<=right && top<=bottom)
        {

        // Right Direction Print
        for(int i=left;i<=right;i++)
        {
            order.push_back(matrix[top][i]);
        }
        top++;

        // Downwards Direction
        for(int i=top;i<=bottom;i++)
        {
            order.push_back(matrix[i][right]);
        }
        right--;

        // Left Direction
        if(top<=bottom) //check if it is single row or not
        {
            for(int i=right;i>=left;i--)
            {
                order.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        
        // Upward Direction
        if(left<=right) //Check if it is single column or not
        {
            for(int i=bottom;i>=top;i--)
            {
                order.push_back(matrix[i][left]);
            }
            left++;
        }
        }
        return order;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends