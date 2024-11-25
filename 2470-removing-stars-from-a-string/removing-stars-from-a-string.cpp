class Solution {
public:
    string removeStars(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='*')
            ans.push_back(s[i]);
            else if(ans.length()>0 && s[i]=='*')
            ans.pop_back();
        }
        return ans;
    }
};