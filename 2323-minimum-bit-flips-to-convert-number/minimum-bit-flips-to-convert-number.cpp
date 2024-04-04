class Solution {
public:
    int cntSetBits(int n){
        int cnt=0;
        while(n!=0)
        {
            if(n&1==1)
            cnt+=(n&1);
            n=n>>1;
        }
        return cnt;
    }
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        return cntSetBits(ans);
    }
};