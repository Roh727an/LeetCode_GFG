class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        // Base Case
        if(n<=1)
        return prices;
        vector<int>NSE(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top() > prices[i])
            {
                st.pop();
            }
            int res=st.empty()? 0 : st.top();

            st.push(prices[i]);

            NSE[i]=res;
        }
        for(int i=0;i<n;i++)
        NSE[i]=prices[i]-NSE[i];

        return NSE;
    }
};