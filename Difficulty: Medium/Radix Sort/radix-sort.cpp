//{ Driver Code Starts
//Initial Template for C++

#include  <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
//User function Template for C++


void p(int arr[],int n){
    cout<<endl<<"Array : ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

int findLargestElement(int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}

void countSort(int arr[],int n,int pos){
    int count[10]={0};
    for(int i=0;i<n;i++)
    {
        int idx=(arr[i]/pos)%10;
        count[idx]++;
    }
    // Find Cumulative Sum
    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    int ans[n];
    for(int i=n-1;i>=0;i--){
        int idx=(arr[i]/pos)%10;
        ans[--count[idx]]=arr[i];
    }
    
    for(int i=0;i<n;i++)
    arr[i]=ans[i];

}
void radixSort(int arr[], int n) 
{ 
   // code here
   int max=findLargestElement(arr,n);
   for(int pos=1;max/pos>0;pos*=10)
   {
       countSort(arr,n,pos);
   }
} 

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
  
        radixSort(arr, n); 
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        
        cout<<endl;
    }
    return 0; 
} 
// } Driver Code Ends