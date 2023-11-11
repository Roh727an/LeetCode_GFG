//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
// 	2 - > Greater
// 1 -> Equal
// 0 -> Less
	int func(int n,int m,int mid)
	{
	    long long ans=1;
	    for(int i=1;i<=n;i++)
	    {
	        ans=ans*mid;
	        if(ans > m)
	        return 2;
	    }
	    if(ans==m) return 1;
	    return 0;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int s=1;
	    int e=m;
	    int mid=(s+e)/2;
	    while(s<=e)
	    {
	        int temp=func(n,m,mid);
	        if(temp==1)
	        return mid;
	        if(temp == 0)
	        s=mid+1;
	        else
	        e=mid-1;
	       // Update Mid
	       mid=(s+e)/2;
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends