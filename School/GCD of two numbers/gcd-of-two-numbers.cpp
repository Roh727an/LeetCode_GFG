//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int eculideanTheorem(int a,int b){
      if(b==0)
      return a;
      return eculideanTheorem(b,a%b);
  }
    int gcd(int a, int b) {
        return eculideanTheorem(min(a,b),max(a,b));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.gcd(a, b);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends