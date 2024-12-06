class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int>mp;
        for(int i=0;i<banned.size();i++)
        mp[banned[i]]++;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(maxSum>= i && mp.find(i)==mp.end()){
                cnt++;
                maxSum=maxSum-i;
            }
            if(maxSum<=0)
            break;
        }
        return cnt;
    }
};