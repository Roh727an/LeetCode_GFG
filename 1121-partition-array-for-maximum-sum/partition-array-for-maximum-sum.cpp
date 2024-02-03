class Solution {
public:
int rec(int idx,vector<int> arr, int k)
{
    int n=arr.size();
    // Base Case
    if(idx>=n)
    return 0;

    // Try all Partition from idx to idx+k
    int len=0,maxEle=INT_MIN,maxSum=INT_MIN;
    for(int i=idx;i<min(idx+k,n);i++)
    {
        len++;
        maxEle=max(maxEle,arr[i]);
        int sum=len*maxEle + rec(i+1,arr,k);
        maxSum=max(maxSum,sum);
    }
    return maxSum;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // return rec(0,arr,k);
        // TABULATION
        int n = arr.size();
    // 1.Create a DP array to store the maximum sum.
    vector<int> dp(n + 1, 0);
    
    // 2.Iterate through the array from right to left.
    for (int ind = n - 1; ind >= 0; ind--) {
        int len = 0;
        int maxEle = INT_MIN;
        int maxSum = INT_MIN;
    // A.Loop through the next k elements
        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxEle = max(maxEle, arr[j]);
            int sum = len * maxEle + dp[j + 1];
            maxSum = max(maxSum, sum);
        }
        // B.Store the computed maximum sum in the DP array.
        dp[ind] = maxSum;
    }
    // 3.The maximum sum after partitioning the entire array is stored in dp[0].
    return dp[0];
    }
};