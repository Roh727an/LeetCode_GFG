//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int BinarySearch(int nums[], int target,int x,int y) {
        int s=x;
        int e=y;
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            e=mid-1;
            else
            s=mid+1;
            mid=s+(e-s)/2;
        }
        return -1;
    }
 int pivot_Element(int nums[],int l,int h)
 {
     int s=l;
     int e=h;
     int mid=s+(e-s)/2;
     while(s<e)
     {
        if(nums[mid]>=nums[0])
        {
            s=mid+1;
        }
        else
        e=mid;

        mid=s+(e-s)/2;
     }
     return s;
 }
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        // 1.Get the Pivot Index
        int pvt_idx=pivot_Element(A,l,h);
        // 2.Check if Element is Right side of Pivot or Not
        if(key>= A[pvt_idx] && key<=A[h])
        return BinarySearch(A,key,pvt_idx,h);
        else
        return BinarySearch(A,key,l,pvt_idx-1);
        
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