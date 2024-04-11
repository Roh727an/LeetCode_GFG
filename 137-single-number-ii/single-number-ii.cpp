class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        // For Bit index
        for(int b=0;b<32;b++){
            int countSetBits=0;
            for(int i=0;i<nums.size();i++)
            {
                // Check if i'th bit is set or Not
                if((nums[i]>>b)&1)
                countSetBits++;
            }
            // If the Set Bit is not Multiple of 3 
            if(countSetBits%3==1)
            ans=ans|(1<<b);
        }
        return ans;
    }
};