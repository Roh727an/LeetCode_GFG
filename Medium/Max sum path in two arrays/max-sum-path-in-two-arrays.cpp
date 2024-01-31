//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int ar1[], int ar2[], int m, int n)
    {
  // initialize indexes for ar1[] and ar2[]
    int i = 0, j = 0;
  
    // Initialize result and current sum through ar1[] and
    // ar2[].
    int result = 0, sum1 = 0, sum2 = 0;
  
    // Below 3 loops are similar to merge in merge sort
    while (i < m && j < n) {
        // Add elements of ar1[] to sum1
        if (ar1[i] < ar2[j])
            sum1 += ar1[i++];
  
        // Add elements of ar2[] to sum2
        else if (ar1[i] > ar2[j])
            sum2 += ar2[j++];
  
        else // we reached a common point
        {
            // Take the maximum of two sums and add to
            // result
            // Also add the common element of array, once
            result += max(sum1, sum2) + ar1[i];
  
            // Update sum1 and sum2 for elements after this
            // intersection point
            sum1 = 0;
            sum2 = 0;
  
            // update i and j to move to next element of
            // each array
            i++;
            j++;
        }
    }
  
    // Add remaining elements of ar1[]
    while (i < m)
        sum1 += ar1[i++];
  
    // Add remaining elements of ar2[]
    while (j < n)
        sum2 += ar2[j++];
  
    // Add maximum of two sums of remaining elements
    result += max(sum1, sum2);
  
    return result;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends