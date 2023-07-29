class Solution {
public:
int FirstOccurance(vector<int>& arr, int target)
{
    int low=0,high=arr.size()-1,mid=(low+high)/2;
    int ans=-1;
    while(low<=high)
    {
        // Equal
        if(arr[mid]==target)
        {
            ans=mid;
            high=mid;
        }
        // Lesser
        if(arr[mid]<target)
        {
            low=mid+1;
        }
        // Greater
        else
        high=mid-1;
        
        mid=(low+high)/2;
    }
    return ans;
}
int LastOccurance(vector<int>& arr, int target)
{
    int low=0,high=arr.size()-1,mid=(low+high)/2;
    int ans=-1;
    while(low<=high)
    {
        // Equal
        if(arr[mid]==target)
        {
        ans=mid;
        low=mid+1;
        }
        // Less
        else if(arr[mid]>target)
        {
            high=mid-1;
        }
        // Greater
        else
        low=mid+1;

        mid=(low+high)/2;
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        // Base Case
        if(nums.size()==1)
        {
            if(nums[0]==target)
            return {0,0};
            else
            return {-1,-1};
        }
        
        vector<int>ans;
        // First Occurance.
        ans.push_back(FirstOccurance(nums,target));
        ans.push_back(LastOccurance(nums,target));
        return ans;
    }
};