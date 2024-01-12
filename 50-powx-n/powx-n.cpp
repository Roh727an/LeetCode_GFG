class Solution {
public:
double rec(double x,long long n,double &ans)
{
    // Base Case
    if(n<=0)
    return ans;

    // n is Odd
    if(n%2)
    {
        ans=ans*x;
        n=n-1;
    }
    else
    {
        x=x*x;
        n=n/2;
    }
    return rec(x,n,ans);
}
    double myPow(double x, int n) {
        long long p=abs(n);
        double ans=1.0;
        ans=rec(x,p,ans);
        if(n<0)
        ans=(double)1.0/ans;
        return ans;
    }
};