//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Base Case -> Single element
        if(n<=1)
        return {-1};
        
        vector<long long> ans(n,-1);
        // 1.Create a Stack 
        stack<long long>st;
        // 2.Traverse Array from Rigt to Left / Last to Start & Check the Following-
        for(int i=n-1;i>=0;i--){
            
            // a. If there is Smaller Element Present in Stack
            //  -> Pop them till Stack is Empty Or Greater Comes
            while(!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }
            // b. If There is No Element in Stack -> -1
            if(st.empty())
            ans[i]=-1;
            
            
            // c. If the Stack Top is Greater than Element -> Stack Top
            else
            ans[i]=st.top();
            
            // Push The Current Element into The Stack
            st.push(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends