class Solution {
public:
    void reverse(vector<int>& nums,int i,int j){
        while(i<=j)
        swap(nums[i++],nums[j--]);
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int n=nums.size();
        // Reverse First N-K ELements
        reverse(nums,0,n-k-1);
        // Reverse Last (N-K) elements
        reverse(nums,n-k,nums.size()-1);
        // Reverse Whole array
        reverse(nums,0,nums.size()-1);
    }
};