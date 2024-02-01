class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        // Sort the Array
        sort(nums.begin(),nums.end());
        // As the array is divisble by 3 so we divide array into size 3
        for(int i=2;i<nums.size();i=i+3)
        {
            // as the array is sorted so min=nums[i-2] & max =nums[i]
            // If max-min <=k then we can divide 
            if(nums[i]-nums[i-2]<=k)
            {
                ans.push_back({nums[i],nums[i-1],nums[i-2]});
            }
            // Else we cannot divide
            else
            {
                return {};
            }
        }
        return ans;
    }
};