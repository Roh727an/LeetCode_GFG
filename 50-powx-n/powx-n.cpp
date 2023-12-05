class Solution {
public:
    double myPow(double x, int n) {
        // BINARY EXPONENTION
        double ans=1.0;
        long long power=n;
        // Negative Power
        if(power<0)
        power=-1*power;
        while(power>0)
        {
            // If Power is ODD
            if(power%2==1)
            {
                ans=ans*x;
                power=power-1;
            }
            // IF Power is EVEN
            else
            {
                x=x*x;
                power=power/2;
            }
        }
        // If the Power was Neagtive then
        if(n<0)
        ans=(double)(1.0) / ans;
        return ans; 
    }
};