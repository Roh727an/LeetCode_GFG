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
    public void rotate(int[] nums, int k) {
        // Reverse 0 to N-1
        int n=nums.length;
        if(n==1)
        return;
        k=k%n;
        reverse(nums,0,n-1);
        // Reverse 0 to k-1
        reverse(nums,0,k-1);
        // Reverse k to n-1
        reverse(nums,k,n-1);
    }
}