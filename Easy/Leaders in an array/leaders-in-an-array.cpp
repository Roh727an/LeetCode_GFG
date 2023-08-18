//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        // Code here
        // Find Right Max
        vector<int>rightMax(n,0);
        // Traverse Right to Left
        int rmax=arr[n-1];
        for(int i=n-1;i>=0;i--)
        {
            rightMax[i]=rmax;
            if(arr[i]>rmax)
            rmax=arr[i];
        }
        // return rightMax;
        vector<int> ans;
        // Check Elements are Greater than Right Max
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=rightMax[i])
            ans.push_back(arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends