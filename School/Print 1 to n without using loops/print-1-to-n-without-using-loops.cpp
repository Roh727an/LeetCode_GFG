//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
void rec(int i,int n)
{
    // Base Condition
    if(i>n)
    return ;
    // Print Value
    cout<<i<<" ";
    // Increment i
    i++;
    // Recursive Call
    rec(i,n);
}
    void printTillN(int N)
    {
        // Write Your Code here
        int i=1;
        rec(i,N);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.printTillN(N);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends