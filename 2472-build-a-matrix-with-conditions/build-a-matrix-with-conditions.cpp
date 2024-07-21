class Solution {
public:
    unordered_map<int, array<int, 2>> mp;
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> res(k, vector<int>(k, 0));
        if(topo(k, rowConditions, 0) == 0 || topo(k, colConditions, 1) == 0)
            return {};
        
        for(auto &pos : mp)
            res[pos.second[0]][pos.second[1]] = pos.first;
        
        return res;
    }
    bool topo(int& k, vector<vector<int>>& vec, int ind)
    {
        vector<int> in(k + 1, 0);
        vector<vector<int>> adj(k + 1);

        for(auto &i : vec)
        {
            adj[i[0]].push_back(i[1]);
            in[i[1]]++;
        }

        int pos = 0;
        queue<int> q;
        for(int i = 1; i < k + 1; i++)
        {
            if(in[i] == 0)
            {
                mp[i][ind] = pos;
                pos += 1;
                q.push(i);
            }
        }

        if(q.empty())
            return 0;

        while(!q.empty())
        {
            for(int &node : adj[q.front()])
            {
                in[node]--;
                if(in[node] == 0)
                {
                    mp[node][ind] = pos;
                    pos += 1;
                    q.push(node);
                }
            }
            q.pop();
        }

        if(pos != k)
            return 0;
        return 1;
    }
};