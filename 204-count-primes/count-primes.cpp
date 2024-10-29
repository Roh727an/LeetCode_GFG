class Solution {
public:
    int countPrimes(int n) {
        // Base Case
        if (n == 0)
            return 0;

        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;
        int cnt = 0;

        for (int i = 2; i < n; i++) {

            // If Prime -> Mark Multiples as Non Prime
            if (primes[i]) {
                cnt++;

                for (int j = 2 * i; j < n; j += i)
                    primes[j] = 0;
            }
        }
        return cnt;
    }
};