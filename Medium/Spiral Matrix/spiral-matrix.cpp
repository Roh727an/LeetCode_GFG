//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &matrix, int n, int m, int k)
    {
        // Your code goes here
        int left=0,top=0,bottom=n-1,right=m-1;
        vector<int>order;
        int cnt=0;
        while(left<=right && top<=bottom)
        {

        // Right Direction Print
        for(int i=left;i<=right;i++)
        {
            cnt++;
            if(cnt==k)
            return matrix[top][i];
        }
        top++;

        // Downwards Direction
        for(int i=top;i<=bottom;i++)
        {
            cnt++;
            if(cnt==k)
            return matrix[i][right];
        }
        right--;

        // Left Direction
        if(top<=bottom) //check if it is single row or not
        {
            for(int i=right;i>=left;i--)
            {
                cnt++;
                if(cnt==k)
                return matrix[bottom][i];
            }
            bottom--;
        }
        
        // Upward Direction
        if(left<=right) //Check if it is single column or not
        {
            for(int i=bottom;i>=top;i--)
            {
                cnt++;
                if(cnt==k)
                return matrix[i][left];
            }
            left++;
        }
        }
        return -1;
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends