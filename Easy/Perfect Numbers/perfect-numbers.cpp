//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        // Base Case
        if(N==1)
        return false;
        long long ans=1;
        for(long long i=2;i*i<=N;i++)
        {
            // Divisor
            if(N%i==0)
            ans+=i + (N/i);
        }
        // Check if Equal
        return ans==N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends