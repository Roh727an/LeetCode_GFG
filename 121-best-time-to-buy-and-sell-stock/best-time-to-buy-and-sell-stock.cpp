class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // BRUTE FORCE
        /*
        int Profit=0;
        int n=prices.size();
        for(int i=0;i<n-1;i++)
        {
            
            for(int j=i+1;j<n;j++)
            {
                int p=prices[j]-prices[i];
                Profit=max(Profit,p);
            }
        }
        return Profit;
        */

        int maxp=0;
        int n=prices.size();
        int ele=INT_MAX;
        int p=0;
        for(int i=0;i<n;i++)
        {
            // Stock Buy
            if(prices[i]<ele)
            ele=prices[i];

            // Stock Sell
            if(prices[i]>ele)
            {
                p=prices[i]-ele;
                maxp=max(maxp,p);
            }
        }
        return maxp;
    }
};