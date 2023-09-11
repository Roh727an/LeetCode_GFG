class StockSpanner {
public:
    StockSpanner() {
    }
    
    stack<pair<int,int>>st;
    int next(int price) {
                // a.Add all days till Stack top Price is Smaller than Current Price
                int days=1;
                while(!st.empty() && st.top().first <= price)
                {
                    days+=st.top().second;
                    st.pop();
                }
                // b.Now add i'th day Stock span is days & push it along price in Stack
                st.push({price,days});
                return days;               
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */