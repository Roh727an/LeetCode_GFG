class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>hash(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
            if(hash[nums[i]]>1)
            return nums[i];
        }
        return -1;
    }
};