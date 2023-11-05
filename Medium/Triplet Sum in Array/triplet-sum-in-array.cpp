//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int nums[], int n, int X)
    {
        //Your Code Here
        /*
        for(int i=0;i<n-1;i++)
        {
            set<int>hashSet;
            for(int j=i+1;j<n;j++)
            {
                int thirdEle=X-(nums[i]+nums[j]);
                // Third Element is Present
                if(hashSet.find(thirdEle)!=hashSet.end())
                {
                    return true;
                }
                // Insert the j'th element into hashSet
                hashSet.insert(nums[j]);
            }
        }
        return false;
        */
                // 2 Pointer's Approch
        // Sort the Array
        sort(nums,nums+n);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int j=i+1;
            int k=n-1;
            // 2 Pointer's Game
            while(j<k)
            {
                // Calculate Sum
                int sum=nums[i]+nums[j]+nums[k];
                // <0 -> Need to Increase
                if(sum<X)
                j++;
                // >0 -> Need to Decrease
                else if(sum>X)
                k--;
                // Equal
                else
                {
                    return true;
                }
            }
        }
        return  false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends