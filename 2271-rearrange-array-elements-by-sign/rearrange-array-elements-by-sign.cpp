class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int pos=0,neg=1;
        for(int i=0;i<nums.size();i++)
        {
            // Positive
            if(pos<nums.size() && nums[i]>=0){
                ans[pos]=nums[i];
                pos=pos+2;
            }
            // Negative
            else{
                ans[neg]=nums[i];
                neg=neg+2;
            }
        }
        return ans;
    }
};