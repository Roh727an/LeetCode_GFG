class Solution {
public:
    void rec(int i,int n,int sum,vector<int>temp,vector<vector<int>>&ans,int k)
    {
        // Base Case
        if(temp.size()==k || i>9)
        {
            if(sum==n && temp.size()==k )
                ans.push_back(temp);
            return ;
        }
        // i can pick 1-9 as my first element
        for(int idx=i;idx<=9;idx++)
        {
            if(idx>n-sum)
            break;

            // Pick 
            sum=sum+idx;
            temp.push_back(idx);
            rec(idx+1,n,sum,temp,ans,k);
            sum=sum-idx;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>>ans;
      vector<int>temp;
    rec(1,n,0,temp,ans,k);
    return ans;
    }
};