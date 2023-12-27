//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        long long firstOcc(vector<long long>arr,long long k){
        long long s=0,e=arr.size()-1,mid=(s+e)/2;
        long long idx=-1;
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

    long long lastOcc(vector<long long> arr,long long k){
        long long s=0,e=arr.size()-1,mid=(s+e)/2;
        long long idx=-1;
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
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        pair<long,long>p;
        p.first=firstOcc(v,x);
        p.second=lastOcc(v,x);
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends