class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>hashSet;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            // Skip
            if(i>0 && nums[i]==nums[i-1])
            continue;

            for(int j=i+1;j<n;j++)
            {
                // Skip
                if(j>i+1 && nums[j]==nums[j-1])
                continue;

                // 2 Pointer's  Game
                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                long long sum=((long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l]);
                if(sum>target)
                    l--;
                else if(sum<target)
                    k++;
                else{
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    hashSet.insert(temp);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1])
                    k++;
                    while(k<l && nums[l]==nums[l+1])
                    l--;
                }
              }
            }
        }
        vector<vector<int>>ans(hashSet.begin(),hashSet.end());
        return ans;
    }
};