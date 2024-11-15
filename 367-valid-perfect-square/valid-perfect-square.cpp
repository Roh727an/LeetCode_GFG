class Solution {
public:
    bool isPerfectSquare(int x) {
        int s=0,e=x;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(mid*mid==x)
            return true;
            else if(mid*mid > x)
            e=mid-1;
            else
                s=mid+1;
        }
        return false;
    }
};