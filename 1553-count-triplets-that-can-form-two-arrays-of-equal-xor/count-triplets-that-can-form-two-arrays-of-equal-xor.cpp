class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int a, b, n = arr.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            a = 0;
            for (int j = i + 1; j < n; j++) {
                a ^= arr[j - 1];
                b = 0;
                for (int k = j; k < n; k++){
                    b ^= arr[k];
                    if (a == b)
                    ans++;
                }
            }
        }
        return ans;
    }
};