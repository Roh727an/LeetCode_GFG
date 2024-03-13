class Solution {
public:
int sum(int s,int e,int n){
    return (n*(s+e))/2;
}
    int pivotInteger(int n) {
        for(int i=1;i<=n;i++)
        {
            // cout<<i<<" "<<sum(1,i,i) <<" "<<sum(i,n,n-i+1)<<endl;
            if(sum(1,i,i)==sum(i,n,n-i+1)){
            return i;
            }
        }
        return -1;
    }
};