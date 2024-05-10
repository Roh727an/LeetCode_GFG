class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // MaxHeap Approch
        int n=arr.size();
        priority_queue<pair<double,pair<int,int>>>pq; // Store k Fractions
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++){
                double fraction=(double)arr[i]/arr[j];
                // Push into Priority Queue
                pq.push({fraction,{arr[i],arr[j]}});
                if(pq.size()>k)
                pq.pop();
            }
        }
        pair<int,int> p=pq.top().second;
            vector<int>ans(2);
            ans[0]=p.first;
            ans[1]=p.second;
            return ans;
    }
};