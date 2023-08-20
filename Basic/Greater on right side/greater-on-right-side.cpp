//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* Function to replace every element with the
	next greatest element */
	void nextGreatest(int arr[], int n) {
	    // code here
	   // Stack Approch
        if(n <= 1)
        return ;
        vector<int>ans;
        // Create a Stack
        stack<int>st;
        // Push -1 as Last Element Does not have any Right
        st.push(-1);
        // My Stack will Contain Ultimate Greater of Right So,
        for(int i=n-1;i>0;i--)
        {
            // If Current Element is Greater Than Stack top then push Stack Top as We Found New Ultimate Greater
            if(arr[i]>st.top())
            st.push(arr[i]);
            // Else Ultimate Greater will be Our Stack Top
            else
            st.push(st.top());
        }
        // My Stack will Contain Ultimate Greater for Each Array Element
        int i=0;
        while(!st.empty())
        {
            arr[i++]=st.top();
            st.pop();
        }
	}


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.nextGreatest(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends