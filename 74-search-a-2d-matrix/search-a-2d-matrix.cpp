class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n*m-1;
        int mid=(low+high)/2;
        while(low<=high)
        {
            // Middle Element
            int middle_element=matrix[mid/m][mid%m];
            // Match
            if(middle_element==target)
            return true;
            // Left
            if(middle_element>target)
            high=mid-1;
            // Right
            else
            low=mid+1;
            // Update Mid
            mid=(low+high)/2;
        }
        return false;
    }
};