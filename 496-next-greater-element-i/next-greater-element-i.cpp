class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums2.size();
        // A. Find NGE of nums2
        // Base Case -> Single element
        if(n<=1)
        return {-1};
        
        vector<int> NGE(n,-1);
        // 1.Create a Stack 
        stack<int>st;
        // 2.Traverse Array from Rigt to Left / Last to Start & Check the Following-
        for(int i=n-1;i>=0;i--){
            
            // a. If there is Smaller Element Present in Stack
            //  -> Pop them till Stack is Empty Or Greater Comes
            while(!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            // b. If There is No Element in Stack -> -1
            if(st.empty())
            NGE[i]=-1;
            
            
            // c. If the Stack Top is Greater than Element -> Stack Top
            else
            NGE[i]=st.top();
            
            // Push The Current Element into The Stack
            st.push(nums2[i]);
        }
        // B. Find elemnts Accoding to nums1
        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    ans[i]=NGE[j];
                    break;
                }
            }
        }
        return ans;
    }
};