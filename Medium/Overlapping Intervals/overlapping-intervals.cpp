//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         //    1.Sort the Intervals
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;

    // 2.Iterate over the Interval
    for(int i=0;i<intervals.size();i++)
    {
        // a.Select an Interval
        int start=intervals[i][0];
        int end=intervals[i][1];

        // b.Skip the intervals that lie inserted interval of our answer List
        if(!ans.empty() && end <= ans.back()[1]){
        //ans.back()-> Take the last element
            continue;
        } 

        for(int j=i+1;j<intervals.size();j++)
        {
            int currStart=intervals[j][0];
            int currEnd=intervals[j][1];
            // Expand Our Selected Interval Range
            if(currStart<=end)
            {
                end=max(end,currEnd);
            }
            else{
                break;
            }
        }
        // Store in Answer List
        ans.push_back({start,end});
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends