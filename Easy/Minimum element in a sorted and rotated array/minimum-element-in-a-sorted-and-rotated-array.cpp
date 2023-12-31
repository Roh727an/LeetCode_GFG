//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int nums[], int n){
        //complete the function here
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        while(s<e){
            if(nums[mid]>nums[e]){
            s=mid+1;
            }
            else
            e=mid;

            mid=(s+e)/2;
        }
        return nums[mid];
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends