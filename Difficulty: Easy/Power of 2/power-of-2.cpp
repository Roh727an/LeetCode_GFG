class Solution {
  public:
    bool isPowerofTwo(int n) {
        // code here
        return (n&(n-1))==0;
    }
};