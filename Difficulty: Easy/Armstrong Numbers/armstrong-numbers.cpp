//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int digitCount(int n){
        int cnt=0;
        while(n>0){
            cnt++;
            n=n/10;
        }
        return cnt;
    }
    string armstrongNumber(int n) {
        // code here
        int digit=digitCount(n);
        long long num=0;
        int temp=n;
        while(temp>0){
            int rem=temp%10;
            if(rem>0)
            num+=pow(rem,digit);
            temp=temp/10;
            if(num>n)
                return "false";
        }
        if(num<n)
        return "false";
        else
        return "true";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends