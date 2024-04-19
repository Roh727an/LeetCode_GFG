class Solution {
public:
    double myPow(double x, int N) {
        double ans=1;
        int n=abs(N);
        while(n>0)
        {
            if(n%2==1)
            {
                ans=ans*x;
                n=n-1;
            }
            else{
                n=n/2;
                x=x*x;
            }
        }
        if(N<0)
        ans=1/ans;
        return ans;
    }
};