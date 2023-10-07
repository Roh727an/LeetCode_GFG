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
    //Function to find list of all words possible by pressing given numbers.
    void rec(int idx,int N,int arr[],string ds,vector<string> &ans,string combinations[]){
        // Base Case
        if(idx>=N)
        {
            ans.push_back(ds);
            return ;
        }
        // Take out the Number
        int number=arr[idx];
        string comb=combinations[number];
        // Try All Possible Combinatons

        for(int i=0;i<comb.length();i++)
        {
            // Push the Charecter
            ds.push_back(comb[i]);
            // Recursive Call for Next index
            rec(idx+1,N,arr,ds,ans,combinations);
            // Backtracking
            ds.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        if(N==0)
        return {};
        vector<string>ans;
        string ds;
        string combinations[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        rec(0,N,a,ds,ans,combinations);

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