class Solution {
public:
    void dfs(int node,vector<int>adjList[],vector<int>&vis){
        vis[node]=1;
        // Visit All Adjecency
        for(auto it:adjList[node]){
            if(!vis[it])
            dfs(it,adjList,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Number of Times DFS Called = Number of Proviences
        int V=isConnected.size();
        vector<int>adjList[V];

        // Convert Adjeceny Matrix to List
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j] && i!=j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);// Bidirected
                }
            }
        }

        // Visited Array
        vector<int>vis(V,0);
        int prv=0;
        // Iterate all Nodes
        for(int i=0;i<V;i++)
        {
            //Node is Not Visited Yet so Call DFS
            if(!vis[i]) 
            {
                prv++;
                dfs(i,adjList,vis);
            }
        }
        return prv;
    }
};