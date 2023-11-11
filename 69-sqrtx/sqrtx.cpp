class Solution {
public:
    int mySqrt(int x) {
        /*
        // LINEAR SEARCH APPROCH
        // Base Case
        if(x==0)
        return 0;
        int ans=1;
        for(int i=1;i<=x;i++)
        {
            if(i*i > x)
            break;

            ans=i;
        }
        return ans;
        */
        // BINARY SEARCH APPROCH
        // Base Case
        if(x==0)
        return 0;
        // return 0;
        int s=1;
        int e=x;
        long long mid=((long long)s+(long long)e)/(long long)2;
        int ans=1;
        while(s<e)
        {
            // Find Our Square Root
            if(mid*mid==x)
            return (int)mid;
            
            // Lesser -> Store
            if(mid*mid < x)
            {
                ans=(int)mid;
                s=mid+1;
            }
            else
            e=mid;
            // Update Mid
            mid=(s+e)/2;
        }
        return ans;
    }
};