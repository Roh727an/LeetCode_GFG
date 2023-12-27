class Solution {
public:
    int firstOcc(vector<int>arr,int k){
        int s=0,e=arr.size()-1,mid=(s+e)/2;
        int idx=-1;
        while(s<=e){
            if(arr[mid]>=k){
                if(arr[mid]==k)
                idx=mid;
                e=mid-1;
            }
            else
            s=mid+1;
            mid=(s+e)/2;
        }
        return idx;
    }

    int lastOcc(vector<int>arr,int k){
        int s=0,e=arr.size()-1,mid=(s+e)/2;
        int idx=-1;
        while(s<=e){
            if(arr[mid]<=k){
                if(arr[mid]==k)
                idx=mid;
                s=mid+1;
            }
            else
            e=mid-1;
            mid=(s+e)/2;
        }
        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>pos;
        pos.push_back(firstOcc(nums,target));
        pos.push_back(lastOcc(nums,target));
        return pos;
    }
};