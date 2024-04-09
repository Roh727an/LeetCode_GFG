class Solution {
public:
    int divide(int dividend, int divisor) {
        // Base Condition
        if (dividend == divisor)
            return 1;
        bool pos = true; // true is Positive
        if ((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0))
            pos = false; // false is Negative

        long n = abs(dividend);
        long d = abs(divisor);

        // DIvision Logic
        long quotient = 0;
        while (n >= d) {
            int cnt = 0;
            // Check the Hight Power of 2 that can be divided
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }

            quotient += (1 << cnt);
            n = n - (d << cnt);
        }
        // OverFlow Conditions
        if (quotient == (1 << 31) && pos)
            return INT_MAX;
        if (quotient == (1 << 31) && !pos)
            return INT_MIN;

        return pos ? quotient : -1 * quotient;
    }
};