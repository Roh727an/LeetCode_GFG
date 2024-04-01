//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int>spf(n+1);
        for(int i=0;i<=n;i++)
        {
            spf[i]=i;
        }
        
        for(int i=2;i*i<=n;i++){
            if(spf[i])//Prime
            {
                for(int j=i*i;j<=n;j+=i){
                    if(spf[j]==j) // Find Multiple
                    spf[j]=i;
                }
            }
        }
        
        vector<int>ans;
        for(int i=0;i<=n;i++)
        ans.push_back(spf[i]);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends