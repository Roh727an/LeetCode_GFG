//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int zero=1;
	    int nonZero=0;
	    while(zero<n && nonZero<n){
	       if(arr[nonZero]==0)
	        {
	            if(arr[zero]!=0)
	            {
	                swap(arr[zero],arr[nonZero]);
	                nonZero++;
	            }
	            else
	            zero++;
	        }
	        else
	        {
	            zero++;
	            nonZero++;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends