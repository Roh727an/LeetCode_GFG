//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  // Find The Maximum Element from the Array
    int maxElement(int nums[], int N,int &sum)
    {
        int maxi=INT_MIN;
        for(int i=0;i<N;i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        return maxi;
    }
// Calculate the Days need to ship when Max Weight is W
    int daysNeedtoShip(int nums[], int N,int w){
        int day=0;
        int sum=0;
        for(int i=0;i<N;i++)
        {   
            sum+=nums[i];
            if(sum > w){
                // cout<<"Break for "<<nums[i]<<" as the Sum "<<sum<<endl;
                day+=1;
                sum=nums[i];
            }
        }
        // cout<<"For w "<<w<<" Days is "<<day<<endl;
        return day;
    }
    int leastWeightCapacity(int weights[], int N, int days) {
        // code here
        
        int sum=0;
        int maxi=maxElement(weights,N,sum);
        int ans=INT_MAX;
        // LINEAR SEARCH
        /*
        for(int i=maxi;i<=sum;i++){
            int d=daysNeedtoShip(weights,N,i);
            if(d<days){
                ans=min(ans,i);
            }
        }
        */
        // BINARY SEARCH
        int s=maxi;
        int e=sum;
        while(s<=e){
            int mid=(e-s)/2 + s;
            int d=daysNeedtoShip(weights,N,mid);
            // Left Half
            if(d < days){
                ans=mid;
                e=mid-1;
            }
            // Right Half
            else
            s=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends