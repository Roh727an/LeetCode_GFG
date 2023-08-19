class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        // Base Case-> SIngle Element
        if(n<=1)
        return {-1};

        //1. Create a Stack
        stack<int>st;
        vector<int>ans(n,-1);
        //2.Traverse the Array Last To First Twice(2*N - 1 TO 0)& Check the Followings-
        // Array index is i%n insetd of just i to obtain Circular Manner
        for(int i=2*n-1 ; i>=0 ; i--)
        {
            //a.If there is Smaller Elements in The Stack Pop Them till Greater Appears Or Stack became Empty
            while(!st.empty() && st.top() <= nums[i%n])
            {
                st.pop();
            }
            // If i is in Range of N To 0 Then only Push into Our Answer Array
            if(i<n)
            {
                // b.If Stack is Empty Then Push -1 Else Push Stack Top
                int ele=st.empty()?-1:st.top();
                ans[i]=ele;
            }
            // Push Current Element into the Stack
            st.push(nums[i%n]);
        }
        return ans;
    }
};