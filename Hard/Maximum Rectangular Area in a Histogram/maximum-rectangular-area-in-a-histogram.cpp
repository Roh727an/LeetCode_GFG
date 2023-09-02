//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        // Your code here
                // 1.Create Stack
        stack<int>st;
        long long maxArea=0;
        // 2.Iterate till Last+1 Index
        for(int i=0;i<=n;i++)
        {
            // Elements having Greater in Stack
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i]))
            {
                long long heightBlock=heights[st.top()];
                st.pop();
                long long width;
                if(st.empty())
                width=i;
                else
                width=i-st.top()-1;

                // Calculate MaxArea
                maxArea=max(maxArea,width*heightBlock);
            }
            st.push(i);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends