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
        int V=isConnected.size();
        vector<int>adjList[V+1];

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
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                prv++;
                dfs(i,adjList,vis);
            }
        }
        return prv;
    }
};