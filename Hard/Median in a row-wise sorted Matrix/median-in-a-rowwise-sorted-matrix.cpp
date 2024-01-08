//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void MaxMinFind(vector<vector<int>> &matrix, int R, int C,int &low,int &high)
    {
        for(int i=0;i<R;i++)
        {
            // Minimum from First Colum
            if(matrix[i][0]<low)
            low=matrix[i][0];
            
            // Maximum from Last Colum
            if(matrix[i][C-1]>high)
            high=matrix[i][C-1];
        }
    }
    int countSmallEq(vector<int> &row,int ele)
    {
        int s=0,e=row.size()-1;
        while(s<=e)
        {
            int md=(s+e)>>1;
            if(row[md]<=mid)
            s=md+1;
            else
            e=md-1;
        }
        return s;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here       
        // 1.Find Maxium(high) & Minimum(low)
        int low=INT_MAX;
        int high=INT_MIN;
        MaxMinFind(matrix,R,C,low,high);
        
        // 2.Binary Search
        while(low<=high)
        {
            int mid=(low+high)/2;
            // Count Number of Smaller or Equal elements of mid in each Row
            int cnt=0;
             for(int i=0;i<R;i++)
            cnt+=countSmallEq(matrix[i],mid);
            
            // If Number of SmallerEq Elements is LesserEq than Median then Move Right
            if(cnt<=(R*C)/2)
            low=mid+1;
             // If Number of SmallerEq Elements is Greater than Median then Move Left
            else
            high=mid-1;
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends