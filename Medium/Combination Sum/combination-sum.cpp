//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
        void rec(int idx,vector<int>arr,vector<int>ds,vector<vector<int>>&ans,int sum)
    {
        // Base Case
        if(idx>=arr.size())
        {
            if(sum==0)
            ans.push_back(ds);
            return ;
        }
        // We Pick the Current index if it is Less than Sum 
        if(arr[idx]<=sum)
        {
            ds.push_back(arr[idx]);
            // Recursive Call For that Index
            rec(idx,arr,ds,ans,sum-arr[idx]);
            // When Come Back from Recursive Call Make Sure to Pop the Last AddedElement
            ds.pop_back(); 
        }
        // Recursive Call For Next Index
        rec(idx+1,arr,ds,ans,sum);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        // Remove All Duplicates Using Set
        set<int>st(A.begin(),A.end());
        // Put the Set Value into a temp Array
        vector<int>arr(st.begin(),st.end());
        // Sort the Array
        sort(arr.begin(),arr.end());
        // Call Recursion
        vector<int>ds;
        vector<vector<int>>ans;
        rec(0,arr,ds,ans,B);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends