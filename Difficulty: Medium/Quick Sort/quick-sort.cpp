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
        // Base Case
        if(low>=high)
        return ;
        // Find the Correct Index of Pivot Element
        int pivotIndex=partition(arr,low,high);
        
        // Recucsively Divide
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=low;
       int i=low,j=high;
       while(i<j){
           while(i<high && arr[pivot]>=arr[i])
           i++;
           while(j>low && arr[pivot]<arr[j])
           j--;
           
           if(i<j)
           swap(arr[i],arr[j]);
       }
       swap(arr[low],arr[j]);
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