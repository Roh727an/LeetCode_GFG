//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here 
                /*
        // LINEAR SEARCH APPROCH
        // Base Case
        if(x==0)
        return 0;
        int ans=1;
        for(int i=1;i<=x;i++)
        {
            if(i*i > x)
            break;

            ans=i;
        }
        return ans;
        */
        // BINARY SEARCH APPROCH
        // Base Case
        if(x==0)
        return 0;
        // return 0;
        long long int s=1;
        long long int e=x;
        long long int mid=(s+e)/(long long int)2;
        long long int ans=1;
        while(s<e)
        {
            // Find Our Square Root
            if(mid*mid==x)
            return mid;
            
            // Lesser -> Store
            if(mid*mid < x)
            {
                ans=mid;
                s=mid+1;
            }
            else
            e=mid;
            // Update Mid
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
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends