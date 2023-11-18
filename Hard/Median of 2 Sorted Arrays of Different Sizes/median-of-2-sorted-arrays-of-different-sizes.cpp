//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Your code goes here
                // APPROCH 1 -> MERGE & FIND MEDIAN 
        /*
        int n1=nums1.size(),n2=nums2.size();
        vector<int>merge;
        int n=n1+n2;
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(nums1[i] < nums2 [j])
            merge.push_back(nums1[i++]);
            else
            merge.push_back(nums2[j++]);
        }
        while(i<n1){
            merge.push_back(nums1[i++]);
        }
        while(j<n2){
            merge.push_back(nums2[j++]);
        }
        // Find Median
        int ele2=merge[n/2];
        int ele1=merge[n/2 - 1];
        if(n%2==0)
        return ((double)ele2 + (double)ele1)/2.0;
        else
        return (double)ele2;
        */
        // APPROCH 2 -> OPTIMIZATION OF APPROCH 1
        /*
        int n1=nums1.size(),n2=nums2.size();
        int n=n1+n2;
        int ele1,ele2,idx2=n/2,idx1=n/2 - 1,cnt=0;
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(nums1[i] < nums2 [j])
            {
                if(cnt==idx1) 
                ele1=nums1[i];
                if(cnt==idx2) 
                ele2=nums1[i];

                i++; 
            }
            else
            {
                if(cnt==idx1) 
                ele1=nums2[j];
                if(cnt==idx2) 
                ele2=nums2[j];
                
                j++; 
            }
            cnt++;
        }
        while(i<n1){
            if(cnt==idx1) 
                ele1=nums1[i];
                if(cnt==idx2) 
                ele2=nums1[i];
                cnt++;
                i++;
        }
        while(j<n2){
            if(cnt==idx1) 
                ele1=nums2[j];
                if(cnt==idx2) 
                ele2=nums2[j];
                cnt++;
                j++;
        }
        // Find Median
        if(n%2==0)
        return ((double)ele2 + (double)ele1)/2.0;
        else
        return (double)ele2;
        */
        // APPROCH 3 -> BINARY SEARCH

        int n1=nums1.size();
        int n2=nums2.size();
        // We consider Array 1 is Smaller So We call Same Function with Swaped Array 
        if(n1>n2)
        return MedianOfArrays(nums2,nums1);
        //TOTAL LENGTH
        int n=n1+n2;
        // Length of LEFT PART
        int left=(n1+n2+1)/2;

        // BINARY SEARCH
        int low=0;
        int high=n1;
        while(low<=high){
            // Calculate Mid
            // mid1 -> Middle of Array 1 -> X elements from Array 1 => Value of X
            int mid1=(low+high)>>1;
            // mid2 -> left-X elements from Array 2 => Value of Y
            int mid2=left-mid1;

            // We found our mid , Now we can calculate l1,l2,r1 & r2
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            // Check Range & Put Value from A1 & A2
            if(mid1 < n1) r1=nums1[mid1];
            if(mid2 < n2) r2=nums2[mid2];
            if(mid1 - 1 >= 0) l1=nums1[mid1-1];
            if(mid2 - 1 >= 0) l2=nums2[mid2-1];

            // Eliminate Halfs based on l1,l2,r1 & r2
            // ANS FOUND(MIDDLE FOUND)
            if(l1<=r2 && l2<=r1)
            {
                // (TOTAL LENGTH) ODD CASE
                if(n%2!=0)
                return max(l1,l2);
                // (TOTAL LENGTH)EVEN CASE
                else
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            // ELIMINATE RIGHT
            if(l1>r2)
            high=mid1-1;
            else
            low=mid1+1;
        }
        return 0;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends