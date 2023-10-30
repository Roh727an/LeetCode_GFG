//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int nums[], int n)
    {
        // code here 
         // Count Values & Replace Values
        int zero=0;
        int one=0;
        int two=0;
        // Count Values
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            zero++;
            else if(nums[i]==1)
            one++;
            else
            two++;
        }
        // Replace Values
        int idx=0;
        while(zero--)
        {
            nums[idx++]=0;
        }
        while(one--)
        {
            nums[idx++]=1;
        }
        while(two--)
        {
            nums[idx++]=2;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends