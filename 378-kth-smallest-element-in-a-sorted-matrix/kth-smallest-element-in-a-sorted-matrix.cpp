class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        /*
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
                cout<<matrix[i][j]<<" "<<hp.top()<<endl;
            }
        }
        return hp.top();
        */
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1];
        while(low<high){
            int mid=low+(high-low)/2;
            int cntSmall=0;
            for(int i=0;i<n;i++)
            {
                int upb=upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
                cntSmall+=upb;
            }
            if(cntSmall < k)
            low=mid+1;
            else
            high=mid;
        }
        return low;
    }
};