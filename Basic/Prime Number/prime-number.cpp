//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPrime(int n){
        // code here
        if (n == 1)
        return 0;
    /*
    // BRUTE FORCE
    for(int i=2;i<n-1;i++){
        if(n%i==0)
        {
            cout<<n<<" is divisible by "<<i<<endl;
        return false;
        }
    }
    */
    //    OPTIMIZED APPROCH
    for (int i = 2; i <=sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // cout << n << " is divisible by " << i << endl;
            return 0;
        }
    }
    return 1;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends