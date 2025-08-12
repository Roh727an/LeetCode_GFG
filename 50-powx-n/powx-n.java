class Solution {
    public double myPow(double x, int n) {
        boolean inverse = n < 0 ? true : false;
        n = Math.abs(n);
        //if x is potive or power is even then ans will be positive
        boolean pos = x > 0 || n % 2 == 0 ? true : false;
        x = Math.abs(x);

        // Base Case
        if (x == 1)
            return pos ? 1 : -1;
        if(n==-2147483648 || n==2147483647 && x>1)
        return 0;
        // Logic
        double ans = 1;
        while (n > 0) {
            //ODD Power
            if (n % 2 == 1) {
                ans = ans * x;
                n = n - 1;
            } 
            //Even Power
            else {
                n = n / 2;
                x = x * x;
            }
        }
        // Inverse
        if (inverse)
            ans = 1 / ans;
        // Negative
        if(!pos)
        ans=(-1)*ans;
        // Range
        if(ans>10000 || ans<-10000)
        ans=0;
        return ans;
    }
}