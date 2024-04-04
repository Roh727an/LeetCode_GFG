class Solution {
public:
    long long power(long long x,long long n,long long &ans){
        if(n<=0)
        return ans;

        if((n&1) == 1)//ODD POwer
        {
            ans*=x;
            n=n-1;
            ans=ans%1000000007;
        }
        else //Even Power
        {
            x*=x;
            n=n/2;
            x=x%1000000007;
        }
        return power(x,n,ans);
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n/2 + n%2;
        long long oddP=1,evenP=1;
        oddP=power(4,odd,oddP);
        evenP=power(5,even,evenP);
        return (evenP*oddP)%1000000007;
    }
};