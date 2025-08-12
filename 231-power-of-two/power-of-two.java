class Solution {
    public boolean isPowerOfTwo(int n) {
        // Base Case
        if(n==0 || n==-2147483648)
        return false;

        return (n & (n-1))==0 ?true:false;
    }
}