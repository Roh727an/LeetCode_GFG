class Solution {
public:
int countSetBits(int n){
    int cnt=0;
    while(n!=0)
    {
        n=n&(n-1);
        cnt++;
    }
    return cnt;
}
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            
            if(countSetBits(i)==k)
            ans+=nums[i];
        }
        return ans;
    }
};