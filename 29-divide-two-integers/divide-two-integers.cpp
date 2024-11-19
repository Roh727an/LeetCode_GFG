class Solution {
public:
    int divide(int dividend, int divisor) {
        // Base Case
        long long dv=dividend,dvs=divisor;
        

        long long s=0,e=abs(dv),mid;
        long long ans=0;
        while(s<=e){
            mid=s+(e-s)/2;
            if(abs(mid*dvs)>abs(dv))
            e=mid-1;
            else
            {
                ans=mid;
                s=mid+1;
            }
        }
        if((dv>0 && dvs<0) || (dv<0 && dvs>0))
        ans=(-1)*ans;

        if(ans>INT_MAX)
        return INT_MAX;
        if(ans<INT_MIN)
        return INT_MIN;

        return ans;

    }
};