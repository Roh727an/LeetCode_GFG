//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string nums){
		int n=nums.length();
        int subsets=(1<<n)-1;
        vector<string>ans;
        for(int bitIdx=1;bitIdx<=subsets;bitIdx++)
        {
            string sub;
            for(int i=0;i<n;i++)
            {
                //i'th Bit set so Take the i'th element
                if((bitIdx>>i)&1)
                sub.push_back(nums[i]);
            }
            ans.push_back(sub);
        }
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