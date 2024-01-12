//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      // Time Complexity-> O(N)
    void rec(long long n,long long i,long long int &ans)
    {
        // Base Case
        if(i>=n)
        return;
        // i is odd index
        if(i%2)
        ans*=4;
        else
        ans*=5;
        
        ans=ans%1000000007;
        rec(n,i+1,ans);
    }

    long long power(long long x,long long n,long long &ans)
    {
        if(n<=0)
        return ans;
        // Odd
        if(n%2)
        {
            ans=ans*x;
            ans=ans%1000000007;
            n=n-1;
        }
        // Even
        else
        {
            x=x*x;
            x=x%1000000007;
            n=n/2;
        }
        return power(x,n,ans);
    }
    int countGoodNumbers(long long n) {
        // code here
        long long int ans=1;
        // Time Complexity-> O(N)
        // rec(n,0,ans);
        // Iterative Approch
        long long odd=n/2;
        long long even=n/2 + n%2;
        long long oddPow=1;
        oddPow=power(4,odd,oddPow);
        long long evenPow=1;
        evenPow=power(5,even,evenPow);
        ans=(evenPow*oddPow)%1000000007;
        return ans;
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