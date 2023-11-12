//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  // Get the Maximum in the Array
int maxiArray(vector<int> piles) {
    int maxi=INT_MIN;
    for(int i=0;i<piles.size();i++)
    {
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
// Calculate  Time to Eat piles of bananas at speed of k
long long calTimeToEat(int k,vector<int>& piles){
    long long time=0;
    for(int i=0;i<piles.size();i++)
    {
        if(piles[i]<k)
        time+=1;
        else{
            time+=(piles[i]/k);
            if(piles[i]%k != 0)
            time+=1;
        }
    }
    return time;
}
    int Solve(int n, vector<int>& piles, int h) {
        // Code here
        // BRUTE FORCE
        int maxP=maxiArray(piles);
        int k=maxP;
        // LINEAR SEARCH APPROCH
        /* 
        for(int i=1;i<=maxP;i++){
            int time=calTimeToEat(i,piles);
            cout<<"k= "<<i<<" time = "<<time<<endl;
            if(time<=h)
            k=min(k,i);
        }
        */
        // Binary Search
        long long s=1;
        long long e=maxP;
        long long mid=(e-s)/2 + s;
        while(s<=e)
        {
            // Calculate time
           long long time=calTimeToEat(mid,piles);
            // Time is Greater than h
            if(time>h)
            s=mid+1;
            else{
                e=mid-1;
                // Store the Current mid
                k=min(k,(int)mid);
            }   
            // Udate mid
            mid=(e-s)/2 + s;
        }
        return k;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends