//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int binary_to_decimal(string binary) {
    // Code here.
    int n=binary.length();
    int digit=1;
    int ans=0;
    //  1   0   1   1   <- Binary String
    //  0   1   2   3   <- Index
    // 2^3 2^2 2^1 2^0  <- Binary to Decimal
    // WE travese the String from last to first 
    // <-----<--------<---- 
    // Power of 2 is increasing also 
    // <-----<--------<---- 
    for(int i=n-1;i>=0;i--){
        if(binary[i]=='1'){
            ans+=digit;
        }
        digit*=2;
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends