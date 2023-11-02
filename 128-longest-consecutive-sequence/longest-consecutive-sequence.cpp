class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // SORT THE ARRAY APPROCH
        // Base Case
        if(nums.size()==0 )
        return 0;
        if(nums.size()==1)
        return 1;

        sort(nums.begin(),nums.end());
        int len=1;
        int lastSmaller=INT_MIN;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(lastSmaller==nums[i]-1)
            {
                cnt++;
                lastSmaller=nums[i];
            }
            else if(lastSmaller!=nums[i])
            {
                cnt=1;
                lastSmaller=nums[i];
            }
            len=max(len,cnt);
        }
        return len;
    }
};