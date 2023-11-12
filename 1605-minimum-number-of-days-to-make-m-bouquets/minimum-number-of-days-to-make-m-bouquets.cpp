class Solution {
public:

// Function to Determine if m Bouquets can be formed at i'th Day
bool canBouquetsFormed(vector<int>& arr, int m, int k,int day){
    int cnt=0;
    int bqt=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<=day)
        cnt++;
        else{
            bqt+=(cnt/k);
            cnt=0;
        }
    }
    bqt+=(cnt/k);
    return bqt>=m;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
    // Base Case
    long long val=m * 1ll * k * 1ll;
    if(val > bloomDay.size())
    return -1;

    // Find Maximum &  Maximum & Minimum Element from the array  
    int maxx=INT_MIN;
    int minn=INT_MAX;
    for(int i=0;i<bloomDay.size();i++)
    {
        maxx=max(maxx,bloomDay[i]);
        minn=min(minn,bloomDay[i]);
    }

    // LINEAR SEARCH -> O((maxx-minn)* O(N))
    /*
    int ans=maxx;
    for(int i=minn;i<=maxx;i++)
    {
        if(canBouquetsFormed(bloomDay,m,k,i))
        return i;
    }
    */

    // BINARY SEARCH
    int low = minn, high = maxx;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canBouquetsFormed(bloomDay,m,k,mid)) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
    }
};