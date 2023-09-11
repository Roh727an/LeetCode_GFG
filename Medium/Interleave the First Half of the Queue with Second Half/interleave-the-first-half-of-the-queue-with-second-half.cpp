//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        // 1.Find the Queue Size
        int n=q.size();
        // 2.Find the Middle of Queue
        int half=n/2;
        // 3.Create a Vector of size of Queue
        vector<int>ans(n);
        // Odd Indexes are for First Half Elements
        for(int i=0;i<n;i+=2)
        {
            ans[i]=q.front();
            q.pop();
        }
        // Even Indexes are for Second Half Elements
        for(int i=1;i<n;i+=2)
        {
            ans[i]=q.front();
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends