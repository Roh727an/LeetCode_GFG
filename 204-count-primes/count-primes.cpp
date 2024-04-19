class Solution {
public:
    int countPrimes(int n) {
        // Sieve Of Eratosthenes Algorithm
        int cnt=0;
        long prime[n+1];
        // Mark all As Prime
        for(int i=2;i<n;i++)
        prime[i]=1;

        for(long i=2;i*i<n;i++)
        {
            if(prime[i]==1)
            {
                // Mark all Multiples as Not Prime
                for(long long j=i*i;j<=n;j+=i)
                prime[j]=0;
            }
        }
        for(int i=2;i<n;i++)
        {
            cnt+=prime[i];
        }
        return cnt;
    }
};