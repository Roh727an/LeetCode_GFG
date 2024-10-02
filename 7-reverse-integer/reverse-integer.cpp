class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        long long num=x;
        if(x<0){
        neg=true;
        num=num*(-1);
        }
        long long rev=0;
        while(num>0)
        {
            rev=rev*10+num%10;
            num=num/10;
        }
         if(neg)
         rev=rev*(-1);

        if(rev>INT_MAX || rev<INT_MIN)
        return 0;
       
        return rev;
    }
};