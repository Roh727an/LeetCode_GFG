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
void rec(int idx,vector<int>arr,vector<vector<int>>&ans,vector<int>ds,int k)
{
    if(idx>=arr.size())
    {
        if(k==0)
        ans.push_back(ds);
        return;
    }
    if(arr[idx]<=k){
        ds.push_back(arr[idx]);
        rec(idx,arr,ans,ds,k-arr[idx]);
        ds.pop_back();
    }
    rec(idx+1,arr,ans,ds,k);
}
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>>ans;
        vector<int>ds;
        set<int>st(A.begin(),A.end());
        vector<int>arr(st.begin(),st.end());
        sort(arr.begin(),arr.end());
        rec(0,arr,ans,ds,B);
        // sort(ans.begin(),ans.end());
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