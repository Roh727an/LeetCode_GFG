class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0, j=0;
        int ans=0,cc=0;
        // /Grow Window
        while(j<s.length()){
            cc+=abs(s[j]-t[j]);
            // Shrink Window
            while(i<s.length() && cc>maxCost){
                cc-=abs(s[i]-t[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};