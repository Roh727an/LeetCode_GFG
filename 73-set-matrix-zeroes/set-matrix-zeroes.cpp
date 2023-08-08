class Solution {
public:
    void setZeroes(vector<vector<int>>& mattrix) {
        /*
        // Approch 1:
        int n=mattrix.size();
        int m=mattrix[0].size();
        // Set Row & Column to 1e9
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mattrix[i][j]==0)
                {
                    // Set entire Row 1e9
                    for(int k=0;k<n;k++)
                    {
                        if(mattrix[k][j]!=0 && mattrix[k][j]!=1e9)
                        mattrix[k][j]=1e9;
                    }
                    // Set entire Column 1e9
                    for(int k=0;k<m;k++)
                    {
                        if(mattrix[i][k]!=0 && mattrix[i][k]!=1e9)
                        mattrix[i][k]=1e9;
                    }
                }
            }
        }
        // Change 1e9 to 0
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mattrix[i][j]==1e9)
                {
                    mattrix[i][j]=0;
                }
            }
        }
    }
    */
    /*
    // Approch 2: Stack/Queue Approch
    int n=mattrix.size();
    int m=mattrix[0].size();
    // 1.Create a Queue(row,col)
    queue<pair<int,int>>q;
    // 2.Traverse Whole Matrix & insert the (row,col) of 0
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mattrix[i][j]==0)
                {
                    // Push row & Column into Queue
                    q.push({i,j});
                }
            }
        }
        // 3.Take out Elements from Queue & Make Row & Column 0
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            // 3.a.Make Row 0
            for(int k=0;k<m;k++)
            mattrix[row][k]=0;
             // 3.a.Make Column 0
            for(int k=0;k<n;k++)
            mattrix[k][col]=0;
        }
        */
    // Approch 3: Row& Column Approch
    int n=mattrix.size();
    int m=mattrix[0].size();
    // 1.Create Row & Column Array
    vector<int>row(n,0);
    vector<int>col(m,0);
    // 2.Traverse the Matrix & mark the Row & Column's of Zero inthe Row,Col Array
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mattrix[i][j]==0)
                {
                    // Mark i'th row & j'th column as 1
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        // 3.Re-traverse the Matrix & Mark all elements in the Row,Column Marked as 0
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]||col[j])
                mattrix[i][j]=0;
            }
        }

    }
};