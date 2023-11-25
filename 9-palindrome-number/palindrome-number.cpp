class Solution {
public:
long long reverseNumber(int n){
    long long rev=0;
    while(n>0 ){
        int rem=n%10;
        rev=rev*10 + rem;
        n=n/10;
    }
    return rev;
}
    bool isPalindrome(int n) {
    if(n<0 || n>2147483647)
    return false;
    if(n<=9)
    return true;
    // Reverse the Number
    long long revNum=reverseNumber(n);
    return n==revNum;
    }
};