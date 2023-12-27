//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int firstOcc(int arr[], int n ,int k){
        int s=0,e=n-1,mid=(s+e)/2;
        int idx=-1;
        while(s<=e){
            if(arr[mid]>=k){
                if(arr[mid]==k)
                idx=mid;
                e=mid-1;
            }
            else
            s=mid+1;
            mid=(s+e)/2;
        }
        return idx;
    }

    int lastOcc(int arr[], int n ,int k){
        int s=0,e=n-1,mid=(s+e)/2;
        int idx=-1;
        while(s<=e){
            if(arr[mid]<=k){
                if(arr[mid]==k)
                idx=mid;
                s=mid+1;
            }
            else
            e=mid-1;
            mid=(s+e)/2;
        }
        return idx;
    }
    vector<int> find(int nums[], int n , int target )
    {
        // code here
        vector<int>pos;
        pos.push_back(firstOcc(nums,n,target));
        pos.push_back(lastOcc(nums,n,target));
        return pos;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends