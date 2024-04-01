//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> getSeive(int l,int r){
      vector<int>prime(r+1);
      for(int i=2;i<=r;i++)
      {
          prime[i]=1;
      }
      for(int i=2;i*i<=r;i++)
      {
          if(prime[i]==1)
          {
              for(int j=i*i;j<=r;j+=i){
                  prime[j]=0;
              }
          }
      }
      return prime;
  }
    int countPrimes(int L, int R) {
        // code here
        vector<int>prime=getSeive(L,R);
        // Prefix Prime Count
        int cnt=0;
        for(int i=2;i<=R;i++)
        {
            cnt+=prime[i];
            prime[i]=cnt;
        }
        int primeCnt=prime[R]-prime[L-1];
        return primeCnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}
// } Driver Code Ends