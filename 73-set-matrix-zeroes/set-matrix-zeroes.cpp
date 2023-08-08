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
    /*
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
        */
        // Optimal Solution
        /*
        Row Array-> matrix[0][0-n]
        Column Array-> matrix[1-m][0]
        matrix[0][0]->col0
        */
        int n=mattrix.size();
        int m=mattrix[0].size();
        int col0=1;
        // 1.Traverse The Matrix & Mark Row,Column Array According to it
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if any element is Zero
                if(mattrix[i][j]==0)
                {
                    // a.Mark i th Row 0
                    mattrix[i][0]=0;

                    // Mark j th Column 0 but check-
                    // 1.if range of j is btween 1-M then Col Array else col0 variable
                    if(j!=0)
                       mattrix[0][j]=0; 
                    else
                        col0=0;
                }
            }
        }
        // 2.Re-Traverse matrix except from First Row(Col Array) & First Column(Row Array) & Convert into Zero According to Row,Col Array
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                // Only Check for NonZero Element
                if(mattrix[i][j]!=0)
                {
                // Check 
                if(mattrix[i][0]==0 || mattrix[0][j]==0)
                    mattrix[i][j]=0;
                }
            }
        }
        // 3.Separately Traverse First Column (First) then First Row(second)
        // a.if the 0th Row is Zero then all the elements in First Column convert into zero
        if(mattrix[0][0]==0)
        {
            for(int j=0;j<m;j++)
                mattrix[0][j]=0;
        }
        // b.if the col0(0th Column) is Zero then all the elements in First Row convert     into zero
        if(col0==0)
        {
            for(int i=0;i<n;i++)
                mattrix[i][0]=0;
        }
    }
};