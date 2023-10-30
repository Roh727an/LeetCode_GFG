class Solution {
public:
int SpaceOpti(vector<int>nums)
{
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<nums.size();i++)
    {
        int pick=nums[i];
        // Edge Case
        if(i>1)
        pick+=prev2;

        int nonPick=0+prev;

        int curr=max(pick,nonPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
    int rob(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        if(nums.size()==1)
        return nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            arr1.push_back(nums[i]);
            if(i!=n-1)
            arr2.push_back(nums[i]);
        }
        // Exclude Last Index
        int ans1=SpaceOpti(arr2);
        // Exclude First Index
        int ans2=SpaceOpti(arr1);

        return max(ans1,ans2);
    }
};