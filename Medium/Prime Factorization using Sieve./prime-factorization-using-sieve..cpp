//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {
        
        
    }

    vector<int> findPrimeFactors(int N) {
        // Write your code here
        vector<int>ans;
        long prime[N+1];
        for(int i=2;i<=N;i++){
            prime[i]=1;
        }
        
        for(int i=2;i*i<=N;i++){
            if(prime[i]==1)
            {
                while(N>0 && N%i==0)
                {
                 ans.push_back(i);
                 N=N/i;
                }
                for(long j=i*i;j<=N;j+=i){
                    prime[j]=0;
                }
                }
            }
            
        if(N!=1)
        ans.push_back(N);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends