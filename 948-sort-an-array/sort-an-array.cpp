class Solution {
public:
        void merge(vector<int>& arr, int l, int m, int r)
    {
        // Your code here
        //  Create a Temp Array
        vector<int>temp;
        // array 1 = arr[l] to arr[m-1]
        // array2 = arr[m] to arr[r]
        int i=l;
        int j=m+1;
        while(i<=m && j<=r)
        {
            if(arr[i]<arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
            temp.push_back(arr[j]);
            j++;  
            }
            
        }
        while(i<=m)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=r)
        {
            temp.push_back(arr[j]);
            j++;
        }
        for(i=l;i<=r;i++)
        arr[i]=temp[i-l];
    }
    public:
    // Divide the Array into Two Halfs till Array has single element
    void mergeSort(vector<int>& arr, int l, int r)
    {
        //code here
        // Base Case-> Single element
        if(l>=r)
        return ;
        // Calculate middle of Array
        int mid=(l+r)/2;
        // Recursion Call One - > Array 1 
        mergeSort(arr,l,mid);
        // Recursion Call Two - > Array 2 
        mergeSort(arr,mid+1,r);
        
        // After Dividing ,it's Time for Merging
        merge(arr,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int>ans=nums;
        int n=nums.size();
        mergeSort(ans,0,n-1);
        return ans;
    }
};