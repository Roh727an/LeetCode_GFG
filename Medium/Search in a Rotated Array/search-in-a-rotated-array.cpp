//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int target){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
      int s=l;
      int e=h;
      int mid=(s+e)/2;
      while(s<=e)
      {
          if(arr[mid]==target)
          return mid;

        // Left Half is Sorted
        if(arr[s]<=arr[mid])
        {
            // IF the ELement is In the Range or Not
            if(arr[s]<=target && arr[mid]>=target){
                e=mid-1;
            }
            else
            s=mid+1;
        }
        // Right Half is Sorted
        else{
            if(arr[mid]<=target && arr[e]>=target){
                s=mid+1;
            }
            else
            e=mid-1;
        }
        // UPDATE MID
        mid=(s+e)/2;
      }
        
    return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends