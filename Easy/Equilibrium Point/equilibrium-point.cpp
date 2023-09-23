//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long A[], int n) {
    
        // Your code here
         long long sum=0;
         for(int i=0;i<n;i++)
         {
             sum+=A[i];
         }
        //   initilize BeforeSum(bs) as 0 & Aftersum(as)=TotalSum
         long long bs=0;
         long long as=sum;
         for(int i=0;i<n;i++)
         {
           //Calculate After Sum
           as=as-A[i];
           //Calculate Before Sum
           bs=sum-as-A[i];
           // cout<<as<<" "<<bs<<endl;
           if(as==bs)
           return i+1;
         }
        return -1;
    }

};


//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends