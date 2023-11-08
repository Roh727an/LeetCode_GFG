class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
    //    Base Case
    if (m == 0) {
        nums1 = nums2;
        return;
    }
    
    int i = 0;
    int j = 0;
    vector < int > ans;
    // Iterate Till Anyone Goes out of Bound
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
        }
        else {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    // Push Remaining Elements
    while (i < m) {
        ans.push_back(nums1[i]);
        i++;
    }
    while (j < n) {
        ans.push_back(nums2[j]);
        j++;
    }
    nums1 = ans;    
    */
    /*
    // OPTIMISED APPROCH 1
    // Base Case
    if (m == 0) {
        nums1 = nums2;
        return;
    }
    int i=0,j=0;

    while(i<m && j<n)
    {
        if(nums1[i] > nums2[j]){
            swap(nums1[i],nums2[j]);
            sort(nums2.begin(),nums2.end());
        }
        i++;
    }    
    for(int j=0;j<n;j++)
    nums1[i+j]=(nums2[j]);
    */
    // OPTIMISED APPROCH 2
    //    Base Case
    if (m == 0) {
        nums1 = nums2;
        return;
    }
    // Transfer all Elements into array1
    for(int i=0;i<n;i++)
    {
        nums1[i+m]=nums2[i];
    }
    sort(nums1.begin(),nums1.end());
    }
};