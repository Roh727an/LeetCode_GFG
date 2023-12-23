class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int singleElement=0;
       for(int i=0;i<nums.size();i++)
       singleElement=singleElement^nums[i];

       return singleElement;
    }
};