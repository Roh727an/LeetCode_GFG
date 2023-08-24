//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    /*
	   // Brute Force Solution
	    int maxOne=0;
	    int maxRow=-1;
	    for(int i=0;i<n;i++)
	    {
	        int cnt=0;
	        for(int j=0;j<m;j++)
	        {
	            if(arr[i][j]==1) cnt++;
	        }
            if(cnt>0 && cnt>maxOne)
            {
                maxOne=cnt;
                maxRow=i;
            }
	    }
	    return maxRow;
	    */
	   // Optimised Solution
	   //Two Pointer's Approch
	   int row=0;
	   int col=m-1;
	   int row_max_one=-1;
	   while(row<n && col>=0)
	   {
	       //Either an Element is 1 or 0
	       //if it is 1 then Store the Row index & col-- to see How much it Shrink
	       if(arr[row][col]==1)
	       {
	           //Store the Row index as it will be Our Desired Answer
	           row_max_one=row;
	           //Column-- to  see How much it will Shrink
	           col--;
	       }
	       //if it is 0 then  Row++ 
	       else
	       row++;
	   }
	   return row_max_one;
	   
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends