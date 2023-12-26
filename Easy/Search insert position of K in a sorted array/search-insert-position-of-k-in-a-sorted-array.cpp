//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>nums, int n, int target)
    {
        // code here
        // int n=nums.size();
        int ans=n;
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        while(s<=e){
            if(nums[mid]==target)
            return mid;

            if(nums[mid]>target){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
            // UPDATE MID
            mid=(s+e)/2;
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
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends