//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {

    //Create A stack For Reversal Purpose
    stack<int>s;
    int n=q.size();
    //Fletch First k elements from Queue & push into Stack
    for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    //Fletch Elements from Stack & Put it back in Queue
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    //Fletch First (n-k) elements from Queue & Push it On the Queue
    for(int i=0;i<n-k;i++)
    {
        int val=q.front();
        q.pop();
        q.push(val);
    }
    
    return q;

}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends