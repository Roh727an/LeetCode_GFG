class Solution {
public:
//   MAXIMUM & SUM OF ARRAY
  int maxElement(vector<int>& A, int n,int& sum){
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(A[i],maxi);
            sum+=A[i];
        }
        return maxi;
    }
// Find Number Of Partition/Split
    int canSplit(vector<int>& A,int n,int maxSum){
        long long summ=A[0];
        int split=1;
        for(int i=1;i<n;i++){
            if(summ+A[i]<=maxSum){
                summ+=A[i];
            }
            else{
                split++;
                summ=A[i];
            }
        }
        return split;
    }
    int splitArray(vector<int>& A, int k) {
        int n=A.size();
        // Base Case(Impossible)
        if(k>n)
        return -1;
        int sum=0;
        int maxi=maxElement(A,n,sum);
        // BINARY SEARCH
        int s=maxi;
        int e=sum;
        int ans=-1;
        while(s<=e){
            int mid=(e-s)/2 + s;
            int split=canSplit(A,n,mid);
            // Remove Right Part
            if(split <= k){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        // cout<<"NOT FOUND"<<endl;
        return ans;
    }
};