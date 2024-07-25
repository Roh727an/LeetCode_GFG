class Solution {
    public:
    void merge(vector<int>&arr, int l, int m, int r)
    {
         // Your code here
         int i=l,j=m+1;
         vector<int>temp;
         while(i<=m && j<=r)
         {
             if(arr[i]<arr[j])
                 temp.push_back(arr[i++]);
             else
              temp.push_back(arr[j++]);
         }
         while(i<=m)
         {
            temp.push_back(arr[i++]);
         }
         while(j<=r)
         {
            temp.push_back(arr[j++]);
         }
         
         for(int i=l;i<=r;i++)
         arr[i]=temp[i-l];
         
    }
    void mergeSort(vector<int>&arr, int l, int r)
    {
        //code here
        if(l>=r)
        return;
        // Calculate mid
        int mid=(l+r)>>1;
        // Left Recursive Call
        mergeSort(arr,l,mid);
        // Right Recursive Call
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};