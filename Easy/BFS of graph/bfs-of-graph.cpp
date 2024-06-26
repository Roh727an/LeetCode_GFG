//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Initital Configuration
        int vis[V]={0};
        queue<int>q;
        q.push(0);
        vis[0]=0;
        vector<int>bfs;
        // BFS LOGIC
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // If Not Visited The Expolore
            if(vis[node]!=1){
                // Mark as Visited
                vis[node]=1;
            bfs.push_back(node);
            // Push it's Neighbours
            for(int i=0;i<adj[node].size();i++)
            q.push(adj[node][i]);
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends