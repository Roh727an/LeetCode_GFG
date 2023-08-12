class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         /*
        // Brute Force -> Space Complexity=> O(N2)
        int ans=-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            int temp=0;
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]==1)
                {
                    temp++;
                }
                else
                break;
            }
            if(temp>ans)
            ans=temp;
        }
        return ans;
        */
        // Better Apprroch
        int ans=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            // Reset Condition
            if(nums[i]==0)
            {
                cnt=0;
            }
            else
            {
                cnt++;
            }
            // Update ans
            ans=max(ans,cnt);
        }
        return ans;
    }
};