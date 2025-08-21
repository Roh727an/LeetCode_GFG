class Solution {
    public int maxSubArray(int[] arr) {
        // Base Case
        if(arr.length==1)
        return arr[0];
        // Subarray Sum Calculate
        int maxSum = Integer.MIN_VALUE;
        int currSum = 0;
        int maxNeg = Integer.MIN_VALUE;
        boolean allNeg = true;
        for (int i = 0; i < arr.length; i++) {
            // Edge Case
            if (arr[i] < 0 && maxNeg < arr[i]) {
                maxNeg = arr[i];
            } 
            else if(arr[i]>=0)
                allNeg = false;

            currSum += arr[i];
            // Calculate Current Sum
            if (currSum < 0)
                currSum = 0;
            // Calculate Maximum Sum
            if (currSum > maxSum)
                maxSum = currSum;
        }

        maxSum=allNeg==true?maxNeg:maxSum;
        return maxSum;
    }   
}