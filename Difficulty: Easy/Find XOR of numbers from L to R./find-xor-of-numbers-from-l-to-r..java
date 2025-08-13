// User function Template for Java

class Solution {
    public static int XOR(int n){
        if(n%4==1)
        return 1;
        else if(n%4==2)
        return n+1;
        else if(n%4==3)
        return 0;
        
        return n;
    }
    public static int findXOR(int l, int r) {
        int xorL=XOR(l-1);
        int xorR=XOR(r);
        return xorL^xorR;
    }
}