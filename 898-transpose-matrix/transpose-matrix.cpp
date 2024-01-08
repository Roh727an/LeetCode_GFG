class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
       vector<vector<int>>ans;
       int n=matrix.size();
       int m=matrix[0].size();
        int i=0;
       for(int col=0;col<m;col++)
       {
           vector<int>temp;
           for(int row=0;row<n;row++)
           {
               temp.push_back(matrix[row][col]);
           }
           ans.push_back(temp);
       } 
       return ans;
    }
};