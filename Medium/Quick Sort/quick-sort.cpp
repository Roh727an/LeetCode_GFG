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
        // Base Condition
        if(low>=high)
        return ;
        
        int pivotEleIdx=partition(arr,arr[low],low,high);
        swap(arr[low],arr[pivotEleIdx]);
        // Recursion Call for low to PVT-1
        quickSort(arr,low,pivotEleIdx-1);
        // Recursion Call for PVT+1 to High
        quickSort(arr,pivotEleIdx+1,high);
    }
    
    public:
    int partition (int arr[],int pivot,int low,int high)
    {
       // Place the Pivot in it's Correct Position
       int small=low;
       for(int i=low+1;i<=high;i++)
       {
           if(arr[i]<pivot){
               small++;
               swap(arr[i],arr[small]);
           }
       }
    
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