class Solution {
public:
int setBits(int N) {
        if(N==0)
        return 0;
        if(N<=2)
        return 1;
        int cnt=0;
        while(N>1)
        {
            cnt+=(N&1);
            N=N>>1;
        }
        if(N==1)
        cnt++;
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        ans.push_back(setBits(i));
        return ans;
    }
};