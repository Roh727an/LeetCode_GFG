//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> s1, s2;
public:

    void enqueue(int x) {
        // 1.Put all Elements from Stack 1 to Stack 2
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // 2.Push into Stack 2
        s2.push(x);
        // 3.Put back all Elements from Stack 2 to Stack 1
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue() {
        // Simple Pop from stack 1
        int ele=s1.top();
        s1.pop();
        return ele;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends