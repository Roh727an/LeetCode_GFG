//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    ll one[n+1],zero[n+1];
	    one[1]=1;
	    zero[1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        zero[i]=(zero[i-1]+one[i-1])%1000000007;
	        one[i]=zero[i-1]%1000000007;
	    }
	    return (zero[n]+one[n])%1000000007;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends