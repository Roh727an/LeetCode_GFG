class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        bool neg=false;
        if(x<0){
        neg=true;
        x=abs(x);
        }

        while(x>0){
            int rem=x%10;
            rev=rev*10 + rem;
            if(rev>INT_MAX)
            return 0;
            x=x/10;
        }

        if(neg)
        rev=-1*rev;

        return rev>INT_MAX || rev <INT_MIN ? 0:rev;

    }
};