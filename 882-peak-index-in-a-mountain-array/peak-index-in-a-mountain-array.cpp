class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size()<3)
        return -1;
        int low=0;
        int high=arr.size()-1;
        int mid=(low+high)/2;
        while(low<high){
            if(arr[mid]>arr[mid+1])
            high=mid;
            else
            low=mid+1;

            mid=(low+high)/2;
        }
        return mid;
    }
};