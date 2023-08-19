//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        // code here
        // Base Case -> Single element
        if(n<=1)
        return {-1};
        
        vector<int> ans(n,-1);
        // 1.Create a Stack 
        stack<int>st;
        // 2.Traverse Array from Rigt to Left / Last to Start & Check the Following-
        for(int i=2*n-1;i>=0;i--){
            
            // a. If there is Smaller Element Present in Stack
            //  -> Pop them till Stack is Empty Or Greater Comes
            while(!st.empty() && st.top() <= arr[i%n])
            {
                st.pop();
            }
            // If i is in the Range then We Only check 
            if(i<n)
            {
                // b. If There is No Element in Stack -> -1
                if(st.empty())
                ans[i]=-1;
                // c. If the Stack Top is Greater than Element -> Stack Top
                else
                ans[i]=st.top();
            }
            // Push The Current Element into The Stack
            st.push(arr[i%n]); 
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends