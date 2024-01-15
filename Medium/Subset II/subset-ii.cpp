//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
  void rec(int i,int n,vector<int>& nums,vector<int>temp,set<vector<int>>&ans)
{
    if(i>=n)
    {
        ans.insert(temp);
        return;
    }
    // Pick up
    temp.push_back(nums[i]);
    rec(i+1,n,nums,temp,ans);
    // Backtracks
    temp.pop_back();
    // Not Pick
    rec(i+1,n,nums,temp,ans);
}
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(),nums.end());
         vector<int>temp;
         set<vector<int>>st;
         rec(0,nums.size(),nums,temp,st);
         vector<vector<int>>ans(st.begin(),st.end());
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends