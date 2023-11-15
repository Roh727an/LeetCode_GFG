//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
// Can k Cows placed betweed dis DISTANCE
    bool canPlaced(vector<int> &stalls,int dis,int k){
        int cnt=1;
        int lastCow=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-lastCow >= dis)
            {
                cnt++;
                lastCow=stalls[i];
            }
        }
        return cnt>=k;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        // 1.Sort the Stalls
        sort(stalls.begin(),stalls.end());
        int maxi=stalls[n-1]-stalls[0];
        // Try all Distance
        int ans=-1;
        // Linear Search
        /*
        for(int i=1;i<=maxi;i++){
            if(canPlaced(stalls,i,k)){
                ans=i;
            }
            else
            break;
        }
        */
        int s=1;
        int e=maxi;
        while(s<=e){
            int mid=(s+e)/2;
            if(canPlaced(stalls,mid,k)){
                ans=mid;
                s=mid+1;
            }
            else
            e=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends