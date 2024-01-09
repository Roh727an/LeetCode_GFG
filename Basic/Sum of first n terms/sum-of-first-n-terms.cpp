//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
//   RECUSION
  long long NSum(long long N,long long sum)
  {
      // code here
        if(N==0)
        return sum;
        
        sum+=powl(N,3);
        return NSum(N-1,sum);
  }
    long long sumOfSeries(long long N) {
        // code here
        return NSum(N,0);
        // return (n*)
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
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends