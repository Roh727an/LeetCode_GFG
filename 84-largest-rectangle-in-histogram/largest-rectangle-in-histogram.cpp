class Solution {
public:
    vector<int> NextSmallerElementsIndex(vector<int>& heights)
    {
        int n=heights.size();
        vector<int> NSE(n);
        // 1.Create a Stack
        stack<int>st;
        // 2.Traverse the array from Last to First
        for(int i=n-1;i>=0;i--)
        {
            // a.If the Stack Contains Greater Element then Pop them out
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            // b.If the Stack Becomes Empty then Insert Last Index as Next Greater
            if(st.empty())
            {
                NSE[i]=n-1;
            } 
            // c.Else  Insert Stack Top - 1 as Next Greater

            else
            {
                NSE[i]=st.top()-1;
            }
            // Simply Insert Current Index into Stack
            st.push(i);
        }
        return NSE;
    }
    vector<int> PreviousNextSmallerElementsIndex(vector<int>& heights)
    {
        int n=heights.size();
        vector<int> PSE(n);
        // 1.Create a Stack
        stack<int>st;
        // 2.Traverse the array from Last to First
        for(int i=0;i<n;i++)
        {
            // a.If the Stack Contains Greater Element then Pop them out
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            // b.If the Stack Becomes Empty then Insert First Index as Previous Greater
            if(st.empty())
            {
                PSE[i]=0;
            } 
            // c.Else  Insert Stack Top + 1 as Previous Greater

            else
            {
                PSE[i]=st.top()+1;
            }
            // Simply Insert Current Index into Stack
            st.push(i);
        }
        return PSE;
    }
    int largestRectangleArea(vector<int>& heights) {
        // Base Case
        if(heights.size()==1)
        return heights[0];
        int n=heights.size();

        // 1.Find Next Smaller Elements Index
        vector<int>NSE=NextSmallerElementsIndex(heights);

        // 2.Find Previous Smaller Elements INdex
        vector<int>PSE=PreviousNextSmallerElementsIndex(heights);
        
        // 3.Find Maximum Area Using Formula  - > (NSE[i]-PSE[i] + 1)*heights[i]
        int maxArea=0;
        for(int i=0;i<heights.size();i++)
        maxArea=max(maxArea,((NSE[i]-PSE[i]+1)*heights[i]));

        return maxArea;
    }
};