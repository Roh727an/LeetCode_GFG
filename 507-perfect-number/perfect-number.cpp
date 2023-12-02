class Solution {
public:
    bool checkPerfectNumber(int num) {
    long sum=0;
    int n=num;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
        sum+=i;
    }
    return sum==num;
    }
};