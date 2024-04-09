//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long divd, long long divs) 
    {
        //Base case
        if(divd==divs)
        return 1;
        bool pos=true;
        
        if((divd>=0 && divs<0) || (divd<=0 && divs>0))
        pos=false;
        
        long long quotient=0;
        long long n=abs(divd);
        long long d=abs(divs);
        
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            quotient+=(1<<cnt);
            n=n-(d<<cnt);
        }
        
        // Overflow Condition
        if(quotient>=(1000000000) && pos)
        return 1000000000;
        if(quotient>=(1000000000) && !pos)
        return -1000000000;
        
        return pos?quotient:-quotient;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends