class Solution {
public:
void rec(int idx,int n,vector<int>nums,vector<int>temp,vector<vector<int>>&ans,int k){
    // Base Case
    if(k==0 || idx>=n)
    {
        if(k==0)
        ans.push_back(temp);
        return;
    }
    // I have n-1 options to pick my first element of the Combination
    for(int i=idx;i<n;i++)
    {
        // As the Array is Sorted sor duplicates will be adjecent
        if(i>idx && nums[i]==nums[i-1])
        continue;

        // If my element is greater than k then break as there are more bigger eleemnt as the array is sorted
        if(nums[i]>k)
        break;

        // Pick the element
        temp.push_back(nums[i]);
        // Recursive Call for Next Index
        rec(i+1,n,nums,temp,ans,k-nums[i]);
        // Backtracks
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort the array so that duplicates become Adjacent
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        rec(0,candidates.size(),candidates,temp,ans,target);
        return ans;
    }
};