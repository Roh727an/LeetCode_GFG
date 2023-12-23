//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int nums[],int n){
        // code here
        vector<int>nonDup;
        nonDup.push_back(nums[0]);
        // Push all NonDuplicates into nonDup Array
        for(int i=1;i<n;i++)
        {
            if(nonDup.back()!=nums[i])
            nonDup.push_back(nums[i]);
        }
        // Put back all non duplicates in front of array
        int k=0;
        for(k=0;k<nonDup.size();k++){
            nums[k]=nonDup[k];
        }
        return k;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends