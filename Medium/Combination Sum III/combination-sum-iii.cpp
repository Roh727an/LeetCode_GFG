//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      void rec(int i,int n,int sum,vector<int>temp,vector<vector<int>>&ans,int k)
    {
        // Base Case
        if(temp.size()==k || i>9)
        {
            if(sum==n && temp.size()==k )
                ans.push_back(temp);
            return ;
        }
        // i can pick 1-9 as my first element
        for(int idx=i;idx<=9;idx++)
        {
            if(idx>n-sum)
            break;

            // Pick 
            sum=sum+idx;
            temp.push_back(idx);
            rec(idx+1,n,sum,temp,ans,k);
            sum=sum-idx;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
    vector<vector<int>>ans;
      vector<int>temp;
    rec(1,n,0,temp,ans,k);
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