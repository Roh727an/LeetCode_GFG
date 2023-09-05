//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int getMaxArea(int heights[], int n)
    {
        // Your code here
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
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int maxArea=0;
        int height[m]={0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==0)
                height[j]=0;
                else
                height[j]++;
            }
            int area=getMaxArea(height,m);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends