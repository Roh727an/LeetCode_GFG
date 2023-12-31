class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // APPROCH 1 -> MERGE & FIND MEDIAN 
        /*
        int n1=nums1.size(),n2=nums2.size();
        vector<int>merge;
        int n=n1+n2;
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(nums1[i] < nums2 [j])
            merge.push_back(nums1[i++]);
            else
            merge.push_back(nums2[j++]);
        }
        while(i<n1){
            merge.push_back(nums1[i++]);
        }
        while(j<n2){
            merge.push_back(nums2[j++]);
        }
        // Find Median
        int ele2=merge[n/2];
        int ele1=merge[n/2 - 1];
        if(n%2==0)
        return ((double)ele2 + (double)ele1)/2.0;
        else
        return (double)ele2;
        */
        // APPROCH 2 -> OPTIMIZATION OF APPROCH 1
        int n1=nums1.size(),n2=nums2.size();
        int n=n1+n2;
        int ele1,ele2,idx2=n/2,idx1=n/2 - 1,cnt=0;
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(nums1[i] < nums2 [j])
            {
                if(cnt==idx1) 
                ele1=nums1[i];
                if(cnt==idx2) 
                ele2=nums1[i];

                i++; 
            }
            else
            {
                if(cnt==idx1) 
                ele1=nums2[j];
                if(cnt==idx2) 
                ele2=nums2[j];
                
                j++; 
            }
            cnt++;
        }
        while(i<n1){
            if(cnt==idx1) 
                ele1=nums1[i];
                if(cnt==idx2) 
                ele2=nums1[i];
                cnt++;
                i++;
        }
        while(j<n2){
            if(cnt==idx1) 
                ele1=nums2[j];
                if(cnt==idx2) 
                ele2=nums2[j];
                cnt++;
                j++;
        }
        // Find Median
        if(n%2==0)
        return ((double)ele2 + (double)ele1)/2.0;
        else
        return (double)ele2;
    }
};