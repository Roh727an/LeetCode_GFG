//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>disTo(V,1e9);
        // Priority Queue {dis,Node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        disTo[S]=0;
        pq.push({S,0});
        
        while(!pq.empty()){
            int node=pq.top().first;  // Get the Node & Distance
            int dis=pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){ // Iterate Adjacency Nodes
                int currDis=it[1]; // Current Node & Distance
                int currNode=it[0];
                int newDis=currDis+dis; // Calculate New Distance
                
                // Check for Better
                if(disTo[currNode]>newDis){
                    disTo[currNode]=newDis;
                    // Push current Node with Distance into Queue
                    pq.push({currNode,newDis});
                }
            }
        }
        return disTo;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends