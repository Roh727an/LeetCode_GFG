//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // code here 
    // 	1.Create Stack
    stack<int>st;
    // 2.Push elements into Stack
    for(int i=0;i<n;i++)
    st.push(i);
    
    int cnt=0;
    // 3.Take Element out
    while(!st.empty() && cnt<n-1)
    {
        // Take Out Frist Two For Comparision
        int first=st.top();
        st.pop();
        int second=st.top();
        st.pop();
        
        if(M[first][second])
        st.push(second);
        else
        st.push(first);
        
        cnt++;
    }
    // Remaining ELement in the Stack is Our Celebraty
    if(st.empty()) return -1;
    int ans=st.top();
    // Check if it is Really Celebraty or Not
     //Row Cheack if All 0 then True
        int zeroCount=0;
        
        for(int i=0;i<n;i++)
        {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        //All Zero?
        if(zeroCount != n)
        {
            return -1;
        }
      
        
        //Col Check if All 1 then True
        int oneCount=0;
        
        for(int i=0;i<n;i++)
        {
            if(M[i][ans]== 1)
                oneCount++;
        }
        
        //All One?
        if(oneCount != n-1)
        {
            return -1;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends