class Solution {
public:
    int search(vector<int>& arr, int target) {
       int low=0;
       int high=arr.size()-1;
       int mid=(low+high)/2;
        // Find the Sorted Part
        while(low<=high)
        {
            // Element found
            if(arr[mid]==target)
            return mid;
            // Elemination 
            // If the Left part is Sorted
            if(arr[low]<=arr[mid])
            {
                // Check if taregt is Present in the Half or not
                if(arr[low]<=target && arr[mid]>=target)
                {
                    // Present ->Move to Left Part
                    high=mid-1;
                }
                // Not Present -> Move to Right Part
                else
                {
                    low=mid+1;
                }
            }

            // Right Part is Sorted
            else{
                // Check if taregt is Present in the Half or not
                if(arr[mid]<=target && arr[high]>=target)
                {
                    // Present ->Move to Right Part
                    low=mid+1;
                }
                // Not Present -> Move to Left Part
                else
                {
                    high=mid-1;
                }
            }
            // Update Mid
            mid=(low+high)/2;
        }
        // element is not present
        return -1;
    }
};