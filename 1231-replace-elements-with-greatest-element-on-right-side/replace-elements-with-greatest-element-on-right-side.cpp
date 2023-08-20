class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // Stack Approch -> T.C = O(2N) & S.C= O(N)
        if(arr.size() <= 1)
        return {-1};
        vector<int>ans;
        // Create a Stack
        stack<int>st;
        // Push -1 as Last Element Does not have any Right
        st.push(-1);
        // My Stack will Contain Ultimate Greater of Right So,
        for(int i=arr.size()-1;i>0;i--)
        {
            // If Current Element is Greater Than Stack top then push Stack Top as We Found New Ultimate Greater
            if(arr[i]>st.top())
            st.push(arr[i]);
            // Else Ultimate Greater will be Our Stack Top
            else
            st.push(st.top());
        }
        // My Stack will Contain Ultimate Greater for Each Array Element
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;

        /*
        // Optimised Approch
        vector<int>ans;
        int max=-1;
        for(int i=arr.size()-1;i>=0;i--)
        {
            ans.push_back(max);
            if(arr[i]>max)
            max=arr[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        */
        
    }
};