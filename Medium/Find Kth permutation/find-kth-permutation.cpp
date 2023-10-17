//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
            string ans="";
        int fact=1;
        vector<int>nums;
        // Step1:Calculate Factorial & Number Array
        for(int i=1;i<n;i++)
        {
            nums.push_back(i);
            fact*=i;
        }
        nums.push_back(n);

        // Step2: Find the 
        k=k-1;//0 based Indexing
        while(true)
        {
            // a.Calcualate Index
            ans+=to_string(nums[k/fact]);
            // b.Erase the Number from Number Array
            nums.erase(nums.begin()+k/fact);
            // c.If Number array is Empty then Break,i.e,our ans is ready
            if(nums.size()==0)
            break;

            // d.Update K & Update Factorial
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends