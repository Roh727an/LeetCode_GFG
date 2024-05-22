class Solution {
public:
bool isPalindrome(int s,int e,string str)
{
    while(s<e)
    {
        if(str[s++]!=str[e--])
        return false;
    }
    return true;
}
    void rec(int idx,int n,string s,vector<string>temp,vector<vector<string>>&ans)
    {
        // Base Case
        if(idx>=n)
        {
            ans.push_back(temp);
            return;
        }
        // Partition
        for(int i=idx;i<n;i++)
        {
            if(isPalindrome(idx,i,s)) // Palindrome
            {
                // Substring
                string pal=s.substr(idx,i-idx+1);
                temp.push_back(pal); // Pick
                rec(i+1,n,s,temp,ans);
                temp.pop_back(); // Backtracks
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        rec(0,s.length(),s,temp,ans);
        return ans;
    }
};