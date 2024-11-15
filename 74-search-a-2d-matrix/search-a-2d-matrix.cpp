class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int s=0,e=m*n-1,mid,r,c,element;
        while(s<=e){
            mid=s+(e-s)/2;
            r=mid/m;
            c=mid%m;
            element=matrix[r][c];
            // Binary Search Conditions
            if(element==target)
            return true;
            else if(element>target)
            e=mid-1;
            else
            s=mid+1;
        }
        return false;
    }
};