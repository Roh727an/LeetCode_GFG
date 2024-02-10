class Solution {
public:
bool isPalindrome(string s,int i,int j)
{
    while(i<j){
        if(s[i++]!=s[j--])
        return false;
    }
    return true;
}
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) 
            {
                if(isPalindrome(s, i, j)) 
                ans++;
            }
        }
        return ans;
    }

};