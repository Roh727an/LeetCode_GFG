class Solution {
    public double myPow(double x, int n) {
        // BASE CASE: anything to power 0 is 1
        if (n == 0) return 1; 

        // use long to handle Integer.MIN_VALUE case
        long exp = n; 
        // Inverse
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1;
        while (exp > 0) {
            // if exp is odd
            if ((exp & 1) == 1) { 
                result *= x;
            }
            // square the base
            x *= x; 
            // divide exponent by 2
            exp >>= 1; 
        }

        return result;
    }
}