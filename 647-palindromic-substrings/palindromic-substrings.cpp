class Solution {
public:
    int expand(string s,int l,int r){
        int cnt=0;
        while(l>=0 && r<s.length() && s[l--]==s[r++])
        {
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            // Odd Expand + Even Expand
            ans=ans+ expand(s,i,i) + expand(s,i,i+1);
        }
        return ans;
    }
};