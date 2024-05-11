class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> ratio;
        int n = quality.size();
        
        for (int i = 0; i < n; ++i) {
                ratio.emplace_back((double)wage[i]/ quality[i], quality[i]);
            }
        // Sort Based on Ratio
        sort(begin(ratio), end(ratio));

        priority_queue<int> pq;
        int qualitySum = 0;
        double ans = DBL_MAX;
        for(auto r:ratio) {
            double rto=r.first;
            qualitySum += r.second;
            pq.push(r.second);
            if(pq.size()>k){
            qualitySum-=pq.top();
            pq.pop();
            }
            if(pq.size()==k){
                ans=min(qualitySum*rto,ans);
            }
        }
        return ans;
    }
};