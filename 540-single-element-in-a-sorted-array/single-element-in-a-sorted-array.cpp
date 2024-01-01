class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n=A.size();
        //Base Cases
	    if(n==1)
	    return A[0];
	    if(A[0]!=A[1])
	    return A[0];
	    if(A[n-1]!=A[n-2])
	    return A[n-1];
	    
	    int s=1;
	    int e=n-2;
	    while(s<=e){
	        int mid=(s+e)/2;
	        if(A[mid]!=A[mid-1] && A[mid]!=A[mid+1])
	        return A[mid];
	        
	        if((mid%2==0 && A[mid]==A[mid+1]) ||(mid%2==1 && A[mid]==A[mid-1]))
	        s=mid+1;
	        else
	        e=mid-1;
	    }
	    return -1;
    }
};