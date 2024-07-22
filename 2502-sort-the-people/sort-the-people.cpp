class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string>mp;
        for(int i=0;i<names.size();i++)
        mp[heights[i]]=names[i];

        vector<string>ans;
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
            ans.insert(ans.begin(),it.second);
        }
        return ans;
    }
};