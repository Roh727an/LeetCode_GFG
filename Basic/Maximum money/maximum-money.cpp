//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximizeMoney(int N , int K) {
        // code here
    int prev=K;
    int prev2=0;
    for(int i=1;i<N;i++)
    {
        int pick=K;
        // Edge Case
        if(i>1)
        pick+=prev2;

        int nonPick=0+prev;

        int curr=max(pick,nonPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;

        cin>>N>>K;

        Solution ob;
        cout << ob.maximizeMoney(N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends