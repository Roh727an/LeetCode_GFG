//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string s;
        while(n>0)
        {
            n-=1;
            long long rem=n%26;
            s.push_back('A'+rem);
            n=n/26;
        }
        
        long long i=0,j=s.length()-1;
        while(i<j)
        {
            swap(s[i++],s[j--]);
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends