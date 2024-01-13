class Solution {
public:
    void rec(int i,int n,vector<int>temp,vector<vector<int>>&ans,vector<int>& nums)
    {
        // Base Case
        if(i>=n)
        {
            ans.push_back(temp);
            return ;
        }
        // Pick an element
        temp.push_back(nums[i]);
        // Recursive Call with picked element
        rec(i+1,n,temp,ans,nums);
        // Pop the Element 
        temp.pop_back();
        // Recursive without picking element
        rec(i+1,n,temp,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        rec(0,nums.size(),temp,ans,nums);
        return ans;
    }
};