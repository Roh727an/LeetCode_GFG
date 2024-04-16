//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	bool isPrime(int n){
	    if(n==1)
	    return false;
	    int cnt=0;
	    for(int i=1;i*i<=n;i++)
	    {
	        if(n%i==0)
	        {
	            cnt++;
	            if(n/i!=i)
	            cnt++;
	        }
	        if(cnt>2)
	        return false;
	    }
	    return true;
	}
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    vector<int>ans;
	    for(int i=1;i*i<=N;i++){
	        if(N%i==0)
	        {
	            if(isPrime(i))
	            ans.push_back(i);
	            if(N/i!=i && isPrime(N/i))
	            ans.push_back(N/i);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends