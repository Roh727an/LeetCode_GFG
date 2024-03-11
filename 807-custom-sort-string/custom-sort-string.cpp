class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>freq;
        for(auto i:s)
        freq[i]++;

        string ans="";
        for(auto i:order){
            while(freq[i]-- > 0)
            ans.push_back(i);
        }

        for(auto [i,j]:freq){
            while(j-- > 0)
            ans.push_back(i);
        }
        return ans;
    }
};