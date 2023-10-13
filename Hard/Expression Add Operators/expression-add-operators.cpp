//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<string> ans;
    string s;
    int target;
    vector<string> addOperators(string s, int target) {
        this->s = s;
        this->target = target;
        rec( 0, "", 0, 0);
        return ans;
    }
     void   rec(int i, const string& path, long resSoFar, long prevNum) {
        // Base Case
        if (i == s.length()) {
            if (resSoFar == target) ans.push_back(path);
            return;
        }
        
        string numStr;
        long num = 0;
        // Run a For Loop for Reamining String Part
        for (int j = i; j < s.length(); j++) {
            // Skip leading zero number
            if (j > i && s[i] == '0') break; 
            // Calculate the current Digit/number & Substring
            numStr += s[j];
            num = num * 10 + s[j] - '0';
            // If it is first number then pick it without adding any operator
            if (i == 0) {
                rec(j + 1, path + numStr, num, num); 
            }
            // Else Tray with all 3 Operators 
            else 
            {
                // + Operator
                rec(j + 1, path + "+" + numStr, resSoFar + num, num);
                // -Operator
                rec(j + 1, path + "-" + numStr, resSoFar - num, -num);
                // * Operator
                rec(j + 1, path + "*" + numStr, resSoFar - prevNum + prevNum * num, prevNum * num); // Can imagine with example: 1-2*3
            }
        }
     }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends