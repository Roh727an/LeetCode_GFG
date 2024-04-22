class Solution {
public:
    void reverse(int s,int e,vector<int>&nums){
        while(s<e)
        swap(nums[s++],nums[e--]);
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int n=nums.size();
        // 1.Reverse First N-K Elements
        reverse(0,n-k-1,nums);
        // 2.Reverse (N-k+1 to N-1) Elements
        reverse(n-k,n-1,nums);
        // 3.Reverse Whole Array
        reverse(0,n-1,nums);
    }
};