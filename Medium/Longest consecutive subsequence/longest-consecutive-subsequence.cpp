//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int N)
    {
              // SORT THE ARRAY APPROCH
        // Base Case
        if(N==0 )
        return 0;
        if(N==1)
        return 1;

        sort(nums,nums+N);
        int len=1;
        int lastSmaller=INT_MIN;
        int cnt=0;
        for(int i=0;i<N;i++)
        {
            if(lastSmaller==nums[i]-1)
            {
                cnt++;
                lastSmaller=nums[i];
            }
            else if(lastSmaller!=nums[i])
            {
                cnt=1;
                lastSmaller=nums[i];
            }
            len=max(len,cnt);
        }
        return len;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends