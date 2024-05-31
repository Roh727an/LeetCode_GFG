class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
                // 1.Find the Xor of All Number
        long xxor=0;
        for(int i=0;i<nums.size();i++)
        xxor^=nums[i];

        // Find the Rightmost Set bit Number
        int rightmost=(xxor&xxor-1)^xxor; 
        // Concept of Bucket
        int b1=0,b2=0;
        for(int i=0;i<nums.size();i++)
        {
            // 1st Bit is Set or Not
            if(nums[i] & rightmost) 
            b1^=nums[i];
            else
            b2^=nums[i];
        }
        return{b1,b2};
    }
};