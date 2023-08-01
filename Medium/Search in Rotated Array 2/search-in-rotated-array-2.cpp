//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& arr, int target) {
        // Code here
        int low=0;
       int high=arr.size()-1;
       int mid=(low+high)/2;
        // Find the Sorted Part
        while(low<=high)
        {
            // Element found
            if(arr[mid]==target || arr[low]==target || arr[high] ==target || arr[mid+1]==target || arr[mid-1]==target)
            return true;
            // Elemination 
            // If the Left part is Sorted
            if(arr[low]<=arr[mid])
            {

                // Check if taregt is Present in the Half or not
                if(arr[low]<=target && arr[mid]>=target)
                {
                    // Present ->Move to Left Part
                    high=mid-1;
                }
                // Not Present -> Move to Right Part
                else
                {
                    low=mid+1;
                }
            }

            // Right Part is Sorted
            else{
                // Check if taregt is Present in the Half or not
                if(arr[mid]<=target && arr[high]>=target)
                {
                    // Present ->Move to Right Part
                    low=mid+1;
                }
                // Not Present -> Move to Left Part
                else
                {
                    high=mid-1;
                }
            }
            // Update Mid
            mid=(low+high)/2;
        }
        // element is not present
        return false;
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends