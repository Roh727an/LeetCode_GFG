//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> nums, int n, int k) {
        // your code here
        // 1.Create a Deque(Store index Not Value)**
        deque<int>dq;
        vector<int>ans;
        // 2.Traverse Array & Check-
        for(int i=0;i<nums.size();i++)
        {
            // a.If Deque has Elements Out of Bound then Pop from Front
            if(!dq.empty()&& dq.front()==i-k)
            {
                dq.pop_front();
            }

            // b.Pop Elements from Deque till Current element is Greater Than dq Back
            while(!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            // c.Insert current Index into Deque
            dq.push_back(i);

            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
         return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends