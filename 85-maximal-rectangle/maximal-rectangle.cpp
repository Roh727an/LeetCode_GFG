class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        // 1.Create Stack
        stack<int>st;
        int maxArea=0;
        // 2.Iterate till Last+1 Index
        for(int i=0;i<=n;i++)
        {
            // Elements having Greater in Stack
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i]))
            {
                int heightBlock=heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                width=i;
                else
                width=i-st.top()-1;

                // Calculate MaxArea
                maxArea=max(maxArea,width*heightBlock);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // 1.Declare a height array of size m(where m = no. of columns of the matrix).
        vector<int>height(m,0);
        int maxArea=0;
        // 2.Now, we will run a loop to visit all the rows of the matrix.
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // a.If a cell contains 1 we will increase the value of the column index by 1
                if(matrix[i][j]=='1')
                height[j]++;
                // If the cell contains 0, we will set 0
                else
                height[j]=0;
            }
            // 3. we will pass the height array i.e. the histogram array to the largestRectangleArea() function and store the maximum area for the row
            int area=largestRectangleArea(height);
            // 4.Max AreaAmong all Histogram will be Our Answer
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};