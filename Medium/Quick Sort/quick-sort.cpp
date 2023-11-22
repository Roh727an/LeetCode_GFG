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
        // code here
        if(low<high){
            // Calculate Pivot Index
            int pivotIndex=partition(arr,low,high);
            // Partition left -> Before Pivot Index
            quickSort(arr,low,pivotIndex-1);
            // Partition Right -> After Pivot Index
            quickSort(arr,pivotIndex+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=arr[low];
       int small=low;
       for(int i=low+1;i<=high;i++){
           if(arr[i]<pivot)
           {
               small++;
               swap(arr[i],arr[small]);
           }
       }
       swap(arr[small],arr[low]);
    // Return Pivot Index
       return small;
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