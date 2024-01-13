class Solution {
public:
void rec(int idx,vector<int>arr,vector<vector<int>>&ans,vector<int>ds,int k)
{
    // Base Case
    if(idx>=arr.size())
    {
        if(k==0)
        ans.push_back(ds);
        return;
    }
    // Pick the element only if the element is lessEq than k 
    if(arr[idx]<=k){
        // pick the element
        ds.push_back(arr[idx]);
        // Recursive Call for picked
        rec(idx,arr,ans,ds,k-arr[idx]);
        // Backtracks
        ds.pop_back();
    }
    // Recursive Call for Not picked
    rec(idx+1,arr,ans,ds,k);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        rec(0,candidates,ans,ds,target);
        return ans;
}
};