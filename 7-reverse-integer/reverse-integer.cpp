class Solution {
public:
    int reverse(int x) {
        long rev=0;
        long num=abs(x);
        int neg=x<0?true:false;
        while(num!=0)
        {
            int dig=num%10;
            num=num/10;
            rev=rev*10 + dig;
        }
        rev=neg?rev*-1:rev;
        if(rev>INT_MAX || rev < INT_MIN)
        return 0;

        return rev;
        


    }
};