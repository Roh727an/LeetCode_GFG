//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    //Function to merge the arrays.
    void SwapGreater(long long nums1[], long long nums2[],int idx1,int idx2)
    {
        if(nums1[idx1] > nums2[idx2])
        {
        swap(nums1[idx1],nums2[idx2]);
        }
    }
    void merge(long long nums1[], long long nums2[], int n, int m) 
    { 
    /*
    // APPROCH 2
    // Base Case
    if (n == 0) {
        nums1 = nums2;
        return;
    }
    int i=0,j=0;
    // i-> 1
    // j->2
    while(i<n && j<m)
    {
        if(nums1[i]>nums2[j])
        {
            swap(nums1[i],nums2[j]);
            sort(nums2,nums2+m);
        }
        i++;
    }  
    */
    // APPROCH 3
    /*
    int left=n-1;//Maximum of Array1 
    int right=0; //Minimum of Array2
    
    while(left>=0 && right<m)
    {
        if(nums1[left]>nums2[right])
        {
            swap(nums1[left],nums2[right]);
            left--;
            right++;
        }
        else
        break;
    }
    // Sort Both the Array
    sort(nums1,nums1+n);
    sort(nums2,nums2+m);
    */
    // APPROCH 4 -.> GAP METHOD
        int len=n+m;
        int gap=(len/2) + (len%2);
        
        while(gap > 0)
        {
            int left=0;
            int right=left + gap;
            
            while(right < len){
                
                if(left < n && right >=n){
                    SwapGreater(nums1,nums2,left,right-n);
                }
                else if(left >= n ){
                    SwapGreater(nums2,nums2,left-n,right-n);
                }
                else{
                    SwapGreater(nums1,nums1,left,right);
                }
                left++,right++;
            }
            if(gap==1) break;
            
            gap=(gap/2) + (gap%2);
        }
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends