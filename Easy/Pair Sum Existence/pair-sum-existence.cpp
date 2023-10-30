//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int n, int sum);
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    int arr[n];  //array of size n
            
        for(int i = 0; i < n; i++)
            cin>>arr[i]; //Input the array
             
        int sum; 
        cin>>sum;
          
        cout<< sumExists(arr, n, sum) <<endl;    
            
	}
}
// } Driver Code Ends


//User function Template for C++

int sumExists(int arr[], int n, int sum){
    //Sort the Array
    sort(arr,arr+n);
    // Two Pointer's Approch
    int left=0;
    int right=n-1;
    while(left<right)
    {
        if(arr[left]+arr[right]==sum)
        return 1;
        if(arr[left]+arr[right] < sum)
        left++;
        else
        right--;
    }
    return 0;
}