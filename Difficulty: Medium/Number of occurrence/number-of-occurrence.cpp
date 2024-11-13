//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
        int firstOccurance(vector<int>& nums, int target){
         int s=0,e=nums.size()-1;
         int fo=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
            fo=mid;
            e=mid-1;
            }
            else if(nums[mid]>target)
            e=mid-1;
            else // Move Right
            s=mid+1;
        }
        return fo;
    }
    int lastOccurance(vector<int>& nums, int target){
         int s=0,e=nums.size()-1;
         int lo=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
            lo=mid;
            s=mid+1;
            }
            else if(nums[mid]>target)
            e=mid-1;
            else // Move Right
            s=mid+1;
        }
        return lo;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int fo=firstOccurance(arr,target);
        int lo=lastOccurance(arr,target);
        if(fo==-1 || lo==-1)
        return 0;
        return lo-fo+1;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends