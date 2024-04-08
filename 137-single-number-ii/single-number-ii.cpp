class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // BIt Manipulation [-2^31 <= nums[i] <= 2^31 - 1]
        int num=0;
        for(int bit=0;bit<32;bit++) //Bits
        {
            int setBits=0;
            for(int i=0;i<nums.size();i++)//Array Elements
            {
                // Check if the i'th bit of the element is Set or Not
                if(nums[i] & (1<<bit))
                setBits++;
            }
            if(setBits%3==1) // 1 is that single appear Number's i'th Set Bit
            {
                // Set the i'th Bit
                num=num | (1<<bit);
            }
        }
        return num;
    }
};