class Solution {
public:
int rec(vector<int>nums,int idx,int xxor){
    if(idx>=nums.size())
    return xxor;
    xxor^=nums[idx];
    int x1=rec(nums,idx+1,xxor);
    xxor^=nums[idx];
    int x2=rec(nums,idx+1,xxor);

    return x1+x2;
}
    int subsetXORSum(vector<int>& nums) 
    {
        int xxor=0;
        return rec(nums,0,xxor);

    }
};