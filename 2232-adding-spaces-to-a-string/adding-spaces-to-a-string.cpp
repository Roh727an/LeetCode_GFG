class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i=0,idx=0;
        string ans="";
        while(i<s.length()){
            if(idx<spaces.size() && spaces[idx]==i)
            {
                ans+=" ";
                idx++;
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};