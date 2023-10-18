//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        // Reverse All the Directed Edges,i.e, u->v => v->u
        vector<int> adjRev[V];
        int indegree[V]={0};
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                // i->it
                // it->i
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        // Push all Terminal Edeges (having indegree 0) into Queue
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int> safeNodes;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it:adjRev[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends