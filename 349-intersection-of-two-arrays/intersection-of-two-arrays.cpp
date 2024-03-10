class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;
        for(int i=0;i<nums1.size();i++)
        {
            mp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            mp2[nums2[i]]++;
        }
        vector<int>ans;
        for(auto it:mp1){
            if(mp2.find(it.first)!=mp2.end())
            ans.push_back(it.first);
        }
        
        return ans;
    }
};