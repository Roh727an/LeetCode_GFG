class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int filled=0,empty=numBottles;
        while(numBottles>0 && numBottles>=numExchange)
        {
            // Drink all Filled Bottle
            empty=empty+filled;
            // Exhange to Fill Bottle
            filled=empty/numExchange;
            // Calculate Remaining Empty Bottle
            empty=empty%numExchange;
            // Calculate total number of bottles
            numBottles=filled+empty;
            // Update Ans
            ans+=filled;
        }
        return ans;
    }
};