class Solution {
    boolean isPrime(int n){
        if(n==1)
        return false;
        if(n==2)
        return true;

        for(int i=2;i<=Math.sqrt(n);i++){
            if(n%i==0)
            return false;
        }
        return true;
    }
    public int diagonalPrime(int[][] nums) {
        int n=nums.length;
        int m=nums.length;
        int prime=0;
        for(int i=0;i<n;i++){
            if(isPrime(nums[i][i]))
            {
                prime=Math.max(prime,nums[i][i]);
            }
            if(isPrime(nums[nums.length-i-1][i]))
            {
                prime=Math.max(prime,nums[nums.length-i-1][i]);
            }
        }
        return prime;
    }
}