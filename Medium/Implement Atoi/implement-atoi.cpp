//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isNumber(char ch)
  {
    return ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9';
  }
    /*You are required to complete this method */
    int rec(string s,int idx,int &num,bool neg)
    {
        // Base Case
        if(idx>=s.length())
        {
            if(neg)
            return num*(-1);
            return num;
        }
        // If it is Not a Digit=> Return false
        if(!isNumber(s[idx]))
        return -1;

        // Get the Digit in Integer
        if(isNumber(s[idx])){
        int dig=s[idx]-'0';
        // Calculate Number
        num=num*10+dig;
        }
        // Increment Index
        idx++;
        // Recursive Call
        return rec(s,idx,num,neg);
    }
    int atoi(string str) {
        //Your code here
        bool neg=false;
        int idx=0;
        if(str[0]=='-'){
        neg=true;
        idx=1;
        }
        int num=0;
        return rec(str,idx,num,neg);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends