//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void rec(int idx,int n,vector<int>nums,vector<int>temp,vector<vector<int>>&ans,int k){
    // Base Case
    if(k==0 || idx>=n)
    {
        if(k==0)
        ans.push_back(temp);
        return;
    }
    // I have n-1 options to pick my first element of the Combination
    for(int i=idx;i<n;i++)
    {
        // As the Array is Sorted sor duplicates will be adjecent
        if(i>idx && nums[i]==nums[i-1])
        continue;

        // If my element is greater than k then break as there are more bigger eleemnt as the array is sorted
        if(nums[i]>k)
        break;

        // Pick the element
        temp.push_back(nums[i]);
        // Recursive Call for Next Index
        rec(i+1,n,nums,temp,ans,k-nums[i]);
        // Backtracks
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        // sort the array so that duplicates become Adjacent
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        rec(0,candidates.size(),candidates,temp,ans,target);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends