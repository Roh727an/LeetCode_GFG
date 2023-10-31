//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int>subArray;
	   // KADANE'S ALGORITHM
	   int sum=0;
	   int maxSum=0;
	   int subStart=-1;
	   int subEnd=-1;
	   int start=-1;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]<0)
	        {
	        sum=0;
	        continue;
	        }
	       // Starting Point
	        if(sum==0)
	        start=i;
	        
	        sum+=a[i];
	        
	       // Update
	       if(sum>maxSum)
	       {
	           maxSum=sum;
	           subStart=start;
	           subEnd=i;
	       }
	       //IF both the SUbarray having same Value
	       if(sum==maxSum)
	       {
	           int prevSize=subEnd-subStart;
	           int currSize=i-start;
	           if(prevSize<currSize)
	           {
	           subStart=start;
	           subEnd=i;
	           }
	       }
	    }
	    
	    for(int i=subStart;i<=subEnd;i++)
	    subArray.push_back(a[i]);
	    if(subStart!=-1 && subEnd!=-1)
	    return subArray;
	    
	    return {-1};
	    
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends