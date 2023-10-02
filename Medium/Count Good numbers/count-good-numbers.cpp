//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     long long power(long long x, long long n){
        if(n==0) return 1;
        if(n==1) return x;
        
        long long ans = power(x,n/2);
        if(n%2==0)
            return ans*ans%1000000007;
        
        return x*ans*ans%1000000007;
    }
    int countGoodNumbers(long long N) {
        // code here
        // int ans=1;
        // ans=count(N,ans);
        long long even_index=(N/2)+(N%2);
        long long odd_index=N-even_index;
        return (power(5,even_index)%1000000007)* (power(4,odd_index)%1000000007) %1000000007 ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;

        cout << ob.countGoodNumbers(N) << endl;
    }
}
// } Driver Code Ends