//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
        bool isPalindrome(int s, int e, string exp)
    {
        while (s < e)
        {
            if (exp[s] != exp[e])
                return false;
            s++;
            e--;
        }
        return true;
    }
    void rec(int idx, string s, vector<string> ds, vector<vector<string>> &ans)
    {
        // Base Case
        if (idx >= s.length())
        {
            ans.push_back(ds);
            return;
        }

        // Partition For Every Possible String
        for (int i = idx; i < s.length(); i++)
        {
            // If the Substring is Palindrome then Only We Move Forward
            if (isPalindrome(idx, i, s))
            {
                ds.push_back(s.substr(idx, i - idx + 1));
                rec(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S)
    {
        // code here
        vector<vector<string>> ans;
        vector<string> ds;
        rec(0, S, ds, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends