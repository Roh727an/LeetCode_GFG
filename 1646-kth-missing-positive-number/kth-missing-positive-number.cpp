class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Brute Force
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k)
            k++;
            else break;
        }
        return k;
    }
};