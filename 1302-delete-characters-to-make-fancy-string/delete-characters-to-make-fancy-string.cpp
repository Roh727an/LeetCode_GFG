class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        ans.push_back(s[0]);
        int cnt=0;
        for(int i=1;i<s.length();i++){
            // Reset
            if(ans.back() != s[i])
                cnt=0;
            // Three Con. Same Char
            else if(cnt>=1 && ans.back() == s[i])
            {
                continue;
            }
            else if(ans.back() == s[i])
            cnt++;
            ans.push_back(s[i]);
        }
        return ans;
    }
};