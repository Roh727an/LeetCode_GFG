//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void reverse(int arr[],int i,int j){
    while(i<j)
    {
        swap(arr[i++],arr[j--]);
    }
}
    void rotateArr(int nums[], int d, int n){
        // code here
        d=d%n;
        // Reverse whole array
        reverse(nums,0,n-1);
        //Reverse first k elements
        reverse(nums,0,n-d-1);
        // Reverse remaining elements
        reverse(nums,n-d,n-1);
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends