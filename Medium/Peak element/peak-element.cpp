//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int nums[], int n)
    {
       // Your code herez
        // Base
        // 1.a.If the Array Contains single elemnt then it is a Peak Element
        if(n==1)
        return 0;
        // b.Last element is Peak Element
        if(nums[n-1] >= nums[n-2])
        return n-1;
        // c.First Element is Peak Element
        if(nums[0] >= nums[1])
        return 0;

        // Search Space is 1 to n-2
        // Binary Search Logic
        int low=1,high=n-2;
        while(low<=high)
        {
            // Calculate mid
            int mid=(low+high)/2;

            // Check if Mid is Peak or Not
            if(nums[mid]>=nums[mid+1] && nums[mid]>=nums[mid-1])
            return mid;

            // If mid is in Decreasing Slope then Peak is on the Left Part
            if(nums[mid]>=nums[mid+1])
            high=mid-1;
            // Else Peak is on the Right part
            else
            low=mid+1;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}
// } Driver Code Ends