//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // APPROCH 1 -> Generate all Possible Subarrays
        /*
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=A[j];
                int len=j-i+1;
                if(sum==0)
                ans=max(ans,len);
            }
        }
        return ans;
        */
        // APPROCH 2 -> Prefix Sum
        unordered_map<int,int>mp;
        int sum=0;
        int maxLen=0;
       for(int i=0;i<n;i++){
           sum+=A[i];
           if(sum==0)
           {
            //   Update Length
            maxLen=i+1;
           }
           else{
            //   IF sum is Previously Found
               if(mp.find(sum)!=mp.end())
               {
                //   Current Index - Previous Found Index
                    int len=i-mp[sum];   
                   maxLen=max(maxLen,len);
               }
               else{
                   mp[sum]=i;
               }
           }
       }
       return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends