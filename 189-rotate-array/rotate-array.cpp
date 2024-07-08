class Solution {
public:
    void reverseArray(vector<int>& nums,int s,int e){
        while(s<e)
        swap(nums[s++],nums[e--]);
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverseArray(nums,0,nums.size()-1-k);
        reverseArray(nums,nums.size()-k,nums.size()-1);
        reverseArray(nums,0,nums.size()-1);
    }
};