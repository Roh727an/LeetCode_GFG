//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edges)
  {
      // code here
      // Vis array will count how many times a node is Visited
    int vis[n] = {0}; // 0 based
    int mxWN = 0;
    for (int i = 0; i < n; i++)
    {
        int source = i;
        int des = edges[i];
        if (des != -1)
        {
            vis[des]+=source;
            if (vis[mxWN] <= vis[des])
                mxWN = des;
        }
    }
    return mxWN;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends