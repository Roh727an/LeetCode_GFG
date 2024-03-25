//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long nums[], int n) {
        // code here
        vector<int>dup;
        for(int i=0;i<n;i++)
        {
            int idx=nums[i]%n;
            nums[idx]+=n;
        }
        for(int i=0;i<n;i++)
        {
            if((nums[i]/n) >=2) // Duplicate
            dup.push_back(i);
        }
        if(dup.size()==0)
        return {-1};
        return dup;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends