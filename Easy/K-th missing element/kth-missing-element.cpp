//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function  
    int i=a[0];
    int idx=0;
    int cnt=0;
    while(i<=a[n-1] && idx<n){
        if(i!=a[idx]){
            cnt++;
            if(cnt==k)
            {
                return i;
            }
            i++;
        }
        else
        {
            idx++;
            i++;
        }
    }
    return -1;
}