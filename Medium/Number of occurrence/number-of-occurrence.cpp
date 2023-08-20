//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
int FirstOcc(int arr[], int n , int target){
    int low=0;
    int high=n-1;
    int ans=-1;
    int mid=(low+high)/2;
    while(low<=high)
    {
        // Equal -> Store index & Go to Left(as First Occ)
        if(arr[mid]==target)
        {
            ans=mid;
            high=mid-1;
        }
        // Lesser -> go to Right
        if(arr[mid]<target)
        {
            low=mid+1;
        }
        // Greater -> go to Left
        else
        high=mid-1;
        // Update Mid
        mid=(low+high)/2;
    }
    return ans;
}

int LastOcc(int arr[], int n , int target){
    int low=0;
    int high=n-1;
    int ans=-1;
    int mid=(low+high)/2;
    while(low<=high)
    {
        // Equal -> Store index & Go to Left(as First Occ)
        if(arr[mid]==target)
        {
            ans=mid;
            low=mid+1;
        }
        // Lesser -> go to Right
        if(arr[mid]>target)
        {
            high=mid-1;
        }
        // Greater -> go to Left
        else
         low=mid+1;
        // Update Mid
        mid=(low+high)/2;
    }
    return ans;
}
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	   // Index of Last Occurance - Index of First Occurance
	   int first=FirstOcc(arr,n,x);
	   int last=LastOcc(arr,n,x);
	   if(first==-1 || last==-1)
	   return 0;
	   return last-first+1;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends