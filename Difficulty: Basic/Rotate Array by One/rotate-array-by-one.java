// // User function Template for Java

class Solution {
     public void reverse(int []arr,int i,int j){
         while(i < j) 
         {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
     }
    public void rotate(int[] arr) {
        // code here
        // Reverse the Whole Array
        reverse(arr,0,arr.length-1);
        // Reverse the array from idx 1 to N-1
        reverse(arr,1,arr.length-1);
        
    }
}