//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      void rec(int idx,int n,vector<int>arr,vector<int>ds,vector<vector<int>>&ans,int sum)
  {
    // Base Case
    if(idx>=arr.size() || n==0 || arr[idx]>sum)
    {
        if(sum==0 && n==0)
        ans.push_back(ds);

        return ;
    }
    // Pick Up Element
    ds.push_back(arr[idx]);
    rec(idx+1,n-1,arr,ds,ans,sum-arr[idx]);
    ds.pop_back();
    // Non Pick
    rec(idx+1,n,arr,ds,ans,sum);
  }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<int>ds;//O(K)
        vector<int>arr;//O(9)
        for(int i=1;i<=9;i++)
        arr.push_back(i);
        vector<vector<int>>ans;//O(N*K)
        rec(0,K,arr,ds,ans,N);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends