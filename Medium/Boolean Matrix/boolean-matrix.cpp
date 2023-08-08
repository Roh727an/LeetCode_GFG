//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        // Row Array-> matrix[1-N][0]
        // Column Array-> matrix[0][1-M]
        int n=matrix.size();
        int m=matrix[0].size();
        int col0=0;
        
        // Traverse the Matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if an element is 1
                if(matrix[i][j]==1)
                {
                    // Mark i'th row 
                    matrix[i][0]=1;
                    // if it is first column then mark in col0
                    if(j!=0)
                        matrix[0][j]=1;
                    else
                        col0=1;
                }
            }
        }
        // Re-Traverse the matrix except First Row & Column & Convert to 1
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                // if an element is not 1 then only convert
                if(matrix[i][j]!=1)
                {
                    // Mark according to First Row & Column
                    if(matrix[i][0]==1 || matrix[0][j]==1)
                    matrix[i][j]=1;
                }
            }
        }
        // Traverse First Row
        if(matrix[0][0]==1)
        {
            for(int j=0;j<m;j++)
            matrix[0][j]=1;
        }
        // Traverse First Column
        if(col0==1)
        {
            for(int i=0;i<n;i++)
            matrix[i][0]=1;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends