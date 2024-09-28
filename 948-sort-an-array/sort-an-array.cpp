class Solution {
public:
void merge(vector<int>& arr, int l, int m,int r) {
        vector<int>a;
         int i=l;
         int j=m+1;
         while(i<=m && j<=r){
             if(arr[i]<arr[j]){
                 a.push_back(arr[i++]);
             }
             else
             {
                 a.push_back(arr[j++]);
             }
         }
         while(i<=m)
         a.push_back(arr[i++]);
         while(j<=r)
         a.push_back(arr[j++]);
         
         for(i=l;i<=r;i++)
         arr[i]=a[i-l];
    }
    void mergeSort(vector<int>& nums,int l,int r){
        if(l>=r)
        return ;

        int mid=(l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};