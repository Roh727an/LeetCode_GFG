//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    void rec(int idx,vector<int>arr,vector<int>ds,set<vector<int>>&st)
  {
    // Base Case
    if(idx>=arr.size())
    {
        st.insert(ds);
        return ;
    }
    // Pick up Element
    ds.push_back(arr[idx]);
    rec(idx+1,arr,ds,st);
    ds.pop_back();
    // Non Pick Up 
    rec(idx+1,arr,ds,st);
  }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        vector<int>ds;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        rec(0,nums,ds,st);
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