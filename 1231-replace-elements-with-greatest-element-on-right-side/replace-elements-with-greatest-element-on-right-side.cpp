class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>rmax;
        int n=arr.size();
        int maxi=-1;
        for(int i=n-1;i>=0;i--)
        {
            rmax.push_back(maxi);
            if(arr[i]>maxi)
            maxi=arr[i];
        }
        reverse(rmax.begin(),rmax.end());
        return rmax;
    }
};