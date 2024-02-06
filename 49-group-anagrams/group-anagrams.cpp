class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hashing Problem
        unordered_map<string,int>mp;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++)
        {
            // Create a temp string for Sorting purpse
            string curr=strs[i];
            sort(curr.begin(),curr.end());
            // If the Sorted String is Present in the Map(Anagrams)
            if(mp.find(curr)!=mp.end())
            {
                // Push strs[i] into Ans
                ans[mp[curr]].push_back(strs[i]);
            }
            // Not Present
            else
            {
                mp[curr]=ans.size();
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};