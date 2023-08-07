//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &matrix, int row, int col, int target)
	{
	    // your code here
	   int start=0;
        int end=col -1;
        while(start<row && end>=0)
        {
            int element=matrix[start][end];
            if(element==target)
            {
                return 1;
            }
            if(element<target)
            {
                start++;
               
            }
            else
            {
                 end--;
            }
        }
        return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends