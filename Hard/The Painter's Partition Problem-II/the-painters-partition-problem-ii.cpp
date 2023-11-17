//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  //   MAXIMUM & SUM OF ARRAY
    int maxElement(int A[], int n,long long& sum){
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(A[i],maxi);
            sum+=A[i];
        }
        return maxi;
    }
// Find Number Of Partition/Split
    long long canSplit(int A[],int n,long long& maxSum){
        long long summ=0;
        long long split=1;
        for(int i=0;i<n;i++){
            if(summ+(long long)A[i] <= maxSum){
                summ+=(long long)A[i];
            }
            else{
                split++;
                summ=A[i];
            }
        }
        return split;
    }
    
    long long minTime(int A[], int n, int k)
    {
         // Base Case(Impossible)
        long long sum=0;
        long long maxi=maxElement(A,n,sum);
        // BINARY SEARCH
        long long s=maxi;
        long long e=sum;
        long long ans;
        while(s<=e){
            long long mid=(e-s)/2 + s;
            long long split=canSplit(A,n,mid);
            // Remove Right Part
            if((int)split <= k){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        // cout<<"NOT FOUND"<<endl;
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends