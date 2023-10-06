//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void rec(int idx,vector<int>arr,vector<int>ds,vector<vector<int>>&ans,int sum)
    {
        // Base Case

            if(sum==0)
            {
            ans.push_back(ds);
            return ;
            }
        // Pick Up & Non Pick Option from 0 to arr.size()-1
        for(int i=idx;i<arr.size();i++)
        {
            // Same Element?-> Idx+1 Mvve one Index Ahed || Go to Next Element
            if(i>idx && arr[i]==arr[i-1])
            continue;
            // Greater Element then Right of Array will be Grater so Break
            if(arr[i]>sum)
            break;
            // Pick Up
            ds.push_back(arr[i]);
            // Recursive Call For that Index
            rec(i+1,arr,ds,ans,sum-arr[i]);
            // When Come Back from Recursive Call Make Sure to Pop the Last AddedElement
            ds.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        vector<int>ds;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        rec(0,candidates,ds,ans,target);
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