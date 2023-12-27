class Solution {
public:
    bool search(vector<int>& arr, int target) {
    int n=arr.size();
      int s=0;
      int e=n-1;
      int mid=(s+e)/2;
      while(s<=e)
      {
          if(arr[mid]==target)
          return true;

        // Minimize Search Space by Skipping Duplicates
        if(arr[s]==arr[mid] && arr[mid]==arr[e])
        {
            s++;
            e--;
            continue;
        }
        // Left Half is Sorted
        if(arr[s]<=arr[mid])
        {
            // IF the ELement is In the Range or Not
            if(arr[s]<=target && arr[mid]>=target){
                e=mid-1;
            }
            else
            s=mid+1;
        }
        // Right Half is Sorted
        else{
            if(arr[mid]<=target && arr[e]>=target){
                s=mid+1;
            }
            else
            e=mid-1;
        }
        // UPDATE MID
        mid=(s+e)/2;
      }
        
    return false;
    }
};