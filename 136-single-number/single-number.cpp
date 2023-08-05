class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Xor all elements in the array 
        // Xor will cut elements that apearing 2 times as a^a=0 & 0^b=b
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans^=nums[i];
        }
        return ans;
    }
};