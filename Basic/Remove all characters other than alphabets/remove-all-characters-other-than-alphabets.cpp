//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string removeSpecialCharacter(string s) {
        // code here
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>'Z' || s[i] < 'A' )&& (s[i]<'a' || s[i] > 'z')){
            s.erase(i,1);
            // Back to previuous Index
            i--;
            }
        }
        return s.length()==0?"-1":s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.removeSpecialCharacter(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends