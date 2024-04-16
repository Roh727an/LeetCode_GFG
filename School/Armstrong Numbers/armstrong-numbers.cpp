//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int digitCount(int n)
  {
      int cnt=0;
      while(n!=0)
      {
          cnt++;
          n=n/10;
      }
      return cnt;
  }
    string armstrongNumber(int n){
        // code here
        int totalDig=digitCount(n);
        int sum=0,temp=n;
        while(temp!=0){
            int dig=temp%10;
            temp=temp/10;
            sum=sum+ pow(dig,totalDig);
            if(sum>n)
                return "No"; 
        }
        if(sum<n)
        return "No"; 
        else
        return "Yes"; 
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