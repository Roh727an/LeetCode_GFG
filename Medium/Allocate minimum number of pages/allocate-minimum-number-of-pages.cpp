//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int maxElement(int A[], int n,int& sum){
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(A[i],maxi);
            sum+=A[i];
        }
        return maxi;
    }
    int canDistributed(int A[],int n,int maxPage){
        long long page=A[0];
        int student=1;
        for(int i=1;i<n;i++){
            if(page+A[i]<=maxPage){
                page+=A[i];
            }
            else{
                student++;
                page=A[i];
            }
        }
        return student;
    }
    int findPages(int A[], int n, int m) 
    {
        //code here
        // Base Case(Impossible)
        if(m>n)
        return -1;
        int sum=0;
        int maxi=maxElement(A,n,sum);
        // cout<<"SUM "<<sum<<" MAXI "<<maxi<<endl;
        // LINEAR SEARCH
        /*
        // Try all From Maxi to Sum
        for(int i=maxi;i<=sum;i++){
            if(canDistributed(A,n,i)==m)
            return i;
        }
        */
        // BINARY SEARCH
        int s=maxi;
        int e=sum;
        int ans=-1;
        while(s<=e){
            int mid=(e-s)/2 + s;
            int student=canDistributed(A,n,mid);
            // Remove Right Part
            if(student <= m){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        // cout<<"NOT FOUND"<<endl;
        return ans;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends