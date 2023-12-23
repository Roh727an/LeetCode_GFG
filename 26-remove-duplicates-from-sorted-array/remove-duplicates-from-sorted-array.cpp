class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>nonDup;
        nonDup.push_back(nums[0]);
        // Push all NonDuplicates into nonDup Array
        for(int i=1;i<nums.size();i++)
        {
            if(nonDup.back()!=nums[i])
            nonDup.push_back(nums[i]);
        }
        // Put back all non duplicates in front of array
        int k=0;
        for(k=0;k<nonDup.size();k++){
            nums[k]=nonDup[k];
        }
        return k;
    }
};