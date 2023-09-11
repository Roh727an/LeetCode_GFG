//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
    //1.Create a Stack of Pair<price,days>
        stack<pair<int,int>>st;
        vector<int>ans(n);
        // 2.Traverse the Prices & Check -
        for(int i=0;i<n;i++)
        {
                // a.Add all days till Stack top Price is Smaller than Current Price
                int days=1;
                while(!st.empty() && st.top().first <= price[i])
                {
                    days+=st.top().second;
                    st.pop();
                }
                // b.Now add i'th day Stock span is days & push it along price in Stack
                st.push({price[i],days});
                ans[i]=days;
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends