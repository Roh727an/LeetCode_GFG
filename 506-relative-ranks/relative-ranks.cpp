class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++)
        pq.push({score[i],i});

        int rank=1;
        vector<string>ans(score.size());
        while(!pq.empty())
        {
            int idx=pq.top().second;
            pq.pop();
            if(rank==1)
                ans[idx]="Gold Medal";
            else if(rank==2)
                ans[idx]="Silver Medal";
            else if(rank==3)
                ans[idx]="Bronze Medal";
            else
                ans[idx]=to_string(rank);
            rank++;
        }
        return ans;
    }
};