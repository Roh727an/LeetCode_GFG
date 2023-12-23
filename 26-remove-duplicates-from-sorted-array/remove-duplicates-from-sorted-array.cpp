class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //T.C O(2N) & S.C O(N)
        /*
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
        */
        // OPTIMAL SOLUTION -> 2 Pointers approch
        int nonDup=0;
        int i=1;
        for(i=1;i<nums.size();i++)
        {
            if(nums[nonDup]!=nums[i])
            {
                nums[nonDup+1]=nums[i];
                nonDup++;
            }
        }
        return nonDup+1;
    }
};