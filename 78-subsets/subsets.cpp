class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subsets=(1<<n)-1;
        vector<vector<int>>ans;
        for(int bitIdx=0;bitIdx<=subsets;bitIdx++)
        {
            vector<int>sub;
            for(int i=0;i<n;i++)
            {
                //i'th Bit set so Take the i'th element
                if((bitIdx>>i)&1)
                sub.push_back(nums[i]);
            }
            ans.push_back(sub);
        }
        return ans;

    }
};