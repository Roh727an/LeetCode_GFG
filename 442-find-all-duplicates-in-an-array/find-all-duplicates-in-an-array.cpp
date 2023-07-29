class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<int>ans;
        for(auto i:m)
        {
            // cout<<i.first<<" "<<i.second<<endl;
        
            if(i.second > 1)
            ans.push_back(i.first);
        }
        return ans;
    }
};