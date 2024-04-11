class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xxor=0,xxor2=0;
        for(int i=0;i<=n;i++){
            if(i!=n)
            xxor^=nums[i];

            xxor2^=i;
        }
        return xxor^xxor2;
    }
};