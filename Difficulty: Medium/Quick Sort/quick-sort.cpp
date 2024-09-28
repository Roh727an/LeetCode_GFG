//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        
        if(low<high)
        {
            // Place Pivot To Its Correct Place
            int partitionIndex=partition(arr,low,high);
            // Left
            quickSort(arr,low,partitionIndex-1);
            // Right
            quickSort(arr,partitionIndex+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=arr[low];
       int i=low,j=high;//i -> First Greater & j-> First Lower from Pivot
       while(i<j){
           while(i<=high && arr[i]<=pivot)
           i++;
           while(j>=low && arr[j]>pivot)
           j--;
        //   Didnot Cross -> Swap
           if(i<j)
           swap(arr[i],arr[j]);
       }
    //   Place Pivot in its Correct Position
    swap(arr[low],arr[j]);
    // Pivot Index-> j
    return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends