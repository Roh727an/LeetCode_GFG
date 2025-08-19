class Solution {
    public int getSecondLargest(int[] arr) {
        // code here
        int max=-1;
        int max2=max;
        for(int i=0;i<arr.length;i++){
            if(arr[i]>max){
                max2=max;
                max=arr[i];
            }
            else if(arr[i]>max2 && arr[i]<max)
            max2=arr[i];
            
        }
            return max2==max?-1:max2;
    }
}