class Solution {
  public:
    int findPosition(int n) {
        // code here
        int pos=0;
        int cnt=0;
        for(int i=0;i<31;i++){
            if((n&1)!=0)
            {
                pos=i+1;
                cnt++;
            }
            n=n>>1;
        }
        if(cnt!=1)
        return -1;
        return pos;
    }
};