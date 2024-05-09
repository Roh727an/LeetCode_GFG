class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long res=0;
        int del=0;
        for(int i=happiness.size()-1;i>=0 && k!=0;i--)
        {
            res+=max(happiness[i]-del,0);
            del++;
            k--;
        }
        return res;
    }
};