class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        priority_queue<int>hp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                hp.push(matrix[i][j]);
                if(hp.size()>k)
                hp.pop();            
            }
        }
        return hp.top();
    }
};