//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        //Your code here
        int len=s.length();
        // Skip the Spaces as well as +,- sign at the begining & count +,-
        int i=0,pos=0,neg=0;
        while(i<len && s[i]==' ')
        {
            i++;
        }
        while(i<len &&  s[i]=='+' || s[i]=='-')
        {
            if(s[i]=='+') pos++;
            else if(s[i]=='-') neg++;
            i++;
        }
        // If pos & neg >0 -> INVALID
        if(pos>0 && neg>0  || pos>1 || neg>1)
        return -1;

        long long int num=0;
        // Convert into Number
        while(i<len && (s[i]>='0' && s[i]<='9'))
        {
            if(num>2147483647)
            break;
            num=(num*10) + (s[i]-'0');
            i++;
        }
        if(s[i]>='a' && s[i]<='z' || s[i]=='+' || s[i]=='.' || s[i]=='-')
            return -1;
        // We get the Num 
        if(neg>0 && num!=0)
        num=-num;

        if(num>2147483647)
        return 2147483647;
        if(num<-2147483648)
        return -2147483648;

        return num;
        
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