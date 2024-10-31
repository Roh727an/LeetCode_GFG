class Solution {
public:
    // Seive
    vector<bool> Seive(int n) {
        // Base Case
        if (n == 0)
            return {};

        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;
        int cnt = 0;

        for (int i = 2; i*i <= n; i++) {

            // If Prime -> Mark Multiples as Non Prime
            if (primes[i]) {
                cnt++;

                for (long long int  j = i*i; j <= n; j += i)
                    primes[j] = 0;
            }
        }
        return primes;
    }
   
    vector<int> closestPrimes(int left, int right) {
        // Base Case
        if(left<=2 && left!=right && right-left>1)
        return {2,3};
        vector<bool>seive=Seive(right+1);

        int prev=-1;
        int minDiff=INT_MAX;
        vector<int>ans(2,-1);
        for(int i=left;i<=right;i++){
            if(seive[i])
            {
                if(prev==-1)
                prev=i;
                else if(i-prev<minDiff)
                {
                    ans[0]=prev;
                    ans[1]=i;
                    minDiff=i-prev;
                }
                prev=i;
            }
        }
        return ans;
        
    }
};