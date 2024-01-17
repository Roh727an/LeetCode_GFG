//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void rec(int digIdx,int len,int digits[],string temp, vector<string>&ans,string mp[])
    {
        // Base Case
        if(digIdx>=len)
        {
            ans.push_back(temp);
            return;
        }
        int digit=digits[digIdx];
        string comb=mp[digit];
        // Try all Combinations
        for(int i=0;i<comb.length();i++)
        {
            // Pick Element
            temp.push_back(comb[i]);
            rec(digIdx+1,len,digits,temp,ans,mp);
            temp.pop_back();
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int digits[], int n)
    {
        //Your code here
        vector<string>ans;
        if(n==0)
        return ans;
        string temp="";
        /*
        map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        */
        // String Array for mapping
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        rec(0,n,digits,temp,ans,mp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends