class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // STL
        // next_permutation(nums.begin(),nums.end());
        // return nums;
        // IMPLEMENTATION OF STL
        
        // 1.Find The Break Point
        int idx=-1;
        int N=nums.size();
        for(int i=N-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                idx=i;
                break;
            }
        }
        
        // Edge Case-> IF there is No Break Point
        if(idx==-1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        // 2.Swap the Least Greater Element from idx+1 to N 
        for(int i=N-1;i>idx;i--)
        {
            if(nums[idx] < nums[i])
            {
                swap(nums[idx],nums[i]);
                break;
            }
        }
        
        // 3.Reverse The Remaing Part from idx+1 to N
        reverse(nums.begin()+idx+1,nums.end());
    }
};