class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        // code here
	    int maxOne=0;
	    int row=0;
	    for(int i=0;i<arr.size();i++)
	    {
            sort(arr[i].begin(),arr[i].end());
	        int one=arr[i].end()-upper_bound(arr[i].begin(),arr[i].end(),0);
	        if(one>maxOne)
	        {
	            row=i;
	            maxOne=one;
	        }
	    }
	    return {row,maxOne};
    }
};