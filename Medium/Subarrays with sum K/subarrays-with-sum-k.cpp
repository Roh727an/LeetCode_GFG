//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // BRUTE FORCE
        /*
        int ans=0;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum=0;
            for(int j=i;j<N;j++)
            {
                sum+=Arr[j];
                if(sum==k)
                ans+=1;
            }
        }
        return ans;
        */
        unordered_map<int,int>mp;
        int ans=0;
        mp[0]=1;
        int preSum=0;
        for(int i=0;i<N;i++)
        {
            preSum+=Arr[i];
            int leftPart=preSum-k;
            ans+=mp[leftPart];
            mp[preSum]+=1;
        }
        return ans;
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
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends