//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // Palindrome Check
    bool isPalindrome(int s,int e,string str)
    {
        while(s<e)
        {
            if(str[s++]!=str[e--])
            return false;
        }
        return true;
    }
    void rec(int idx,string s,vector<string>temp,vector<vector<string>>& ans)
    {
        //Base Case
          if(idx>=s.length())
          {
              ans.push_back(temp);
              return ;
          }
        //   Partition
        for(int i=idx;i<s.length();i++)
        {
            // IF PARTITION OF CURRENT INDEX IS PALIDROME
            if(isPalindrome(idx,i,s))
            {
                string partitionStr=s.substr(idx,i-idx+1);
                // push into temp
                temp.push_back(partitionStr);
                rec(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string>ds;
        vector<vector<string>>ans;
        rec(0,S,ds,ans);
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