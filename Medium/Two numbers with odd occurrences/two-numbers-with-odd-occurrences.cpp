//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int xxor=0;
        for(long long int i=0;i<N;i++)
        xxor^=Arr[i];
        
        long long int rightMost=(xxor&xxor-1)^xxor;
        long long int b1=0,b2=0;
        for(long long int i=0;i<N;i++)
        {
            if(Arr[i]&rightMost)
            b1^=Arr[i];
            else
            b2^=Arr[i];
        }
        if(b1>b2)
        return {b1,b2};
        else
        return {b2,b1};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends