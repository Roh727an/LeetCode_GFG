class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Bit Manipulation
        int n=1<<nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            vector<int>subset;
            for(int j=0;j<nums.size();j++)
            {
                // Check Set bit ->Pick
                if(i & (1<<j))
                subset.push_back(nums[j]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};