//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void rec(int i,string s,string temp,vector<string>&ans)
	{
	    if(i>=s.length())
	    {
	        if(temp.length()>=1)
	        ans.push_back(temp);
	        return ;
	    }
	    temp.push_back(s[i]);
	     rec(i+1,s,temp,ans);
	    
	    temp.pop_back();
	     rec(i+1,s,temp,ans);
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		     rec(0,s,"",ans);
		     sort(ans.begin(),ans.end());
	    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends