//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        // Base Case
        if(start==end) 
        return 0;
        // 1.Create a Queue(node,steps) & distance Array(MAX)
        queue<pair<int,int>>q;
        int mod=100000;
        vector<int>disTo(mod,1e9);
        // 2.Mark the Source(start) Distance as 0 & push into Queue
        disTo[start]=0;
        q.push({start,0});
        // 3.Pop the element from the front of the queue and look out for its adjacent nodes
        while(!q.empty())
        {
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            // 3.a.Check for All Elements in Array(Multiplication)
            for(auto it:arr)
            {
                int num = (it * node )%mod;
                // 3.b. Check if It has Better dist Value Than Previous
                if(steps+1<disTo[num])
                {
                    // 3.c.Check if The number is End or Not,if Yes Then Return Step+1
                    if(num==end) 
                    return steps+1;
                    // if No then Update & Push into Queue
                    disTo[num]=steps+1;
                    q.push({num,steps+1});
                }
            }
        }
        // 4.If The Queue Becomes Empty & End is Not Found Return -1
        return -1;
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends