class Solution {
public:
    // Can k Cows placed betweed dis DISTANCE
    bool canPlaced(vector<int> &arr,int dis,int k){
        int cnt=1;
        int lastCow=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-lastCow >= dis)
            {
                cnt++;
                lastCow=arr[i];
            }
        }
        return cnt>=k;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int maxi=position[position.size()-1]-position[0];
        // Try all Distance
        int ans=-1;
        int s=1;
        int e=maxi;
        while(s<=e){
            int mid=(s+e)/2;
            if(canPlaced(position,mid,m)){
                ans=mid;
                s=mid+1;
            }
            else
            e=mid-1;
        }
        return ans;
    }
};