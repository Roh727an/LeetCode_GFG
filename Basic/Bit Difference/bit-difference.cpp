//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int cntSetBits(int n){
        int cnt=0;
        while(n!=0)
        {
            if(n&1==1)
            cnt+=(n&1);
            n=n>>1;
        }
        return cnt;
    }
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int start, int goal){
        
        // Your logic here
        int ans=start^goal;
        return cntSetBits(ans);
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}
// } Driver Code Ends