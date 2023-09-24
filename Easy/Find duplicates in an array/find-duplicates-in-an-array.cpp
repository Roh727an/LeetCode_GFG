//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        // Create an Ans array which acts as an HashMap
        // S.C->O(N) not Auxaliry as it is Demanded by Question
        vector<int>ans(n,0);
        // Run a For Loop To Count Frequencies of Elements
        for(int i=0;i<n;i++)
        {
            ans[arr[i]]=ans[arr[i]]+1;
        }
        // Move Zeroos to End
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(ans[i]>1)
            {
            // We have to Store then Number not the Number of Occurance
            ans[j]=i;
            j++;
            }
        }
        // Pop out the Zeros
        for(int i=j;i<n;i++)
        ans.pop_back();
        // If there is No Element return -1
        return ans.size()==0? vector<int>{-1} : ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends